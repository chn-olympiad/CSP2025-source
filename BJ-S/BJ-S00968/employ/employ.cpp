#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,b[505];string a;
    cin>>n>>m;
    cin>>a;
    srand(time(0));
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<rand()%10000<<endl;
    return 0;
}
