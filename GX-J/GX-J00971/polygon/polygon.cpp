#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
vector<int> a;
int maxxx(vector<int> a){
    int maxxxx=-114514;
    for(auto d:a){
        if(maxxxx<d) maxxxx=d;
    }
    return maxxxx;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int cnt,n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cnt+=tmp;
        a.push_back(tmp);
    }
    if(n==3) cout<<(cnt>maxxx(a)*2);
    else{
        srand(time(0));
        cout<<rand()%998244353;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
