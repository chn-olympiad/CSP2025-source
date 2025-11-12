#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);//printf("",); scanf("",);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m,r_s;
    cin>>n>>m>>r_s;
    int tmp=n*m;
    a[r_s]++;
    for(int i=1;i<tmp;i++){
        int j;
        cin>>j;
        a[j]++;
    }
    int sum=0;
    for(int i=100;i>=r_s;i--){
        sum+=a[i];
    }
    cout<<(sum-1)/n+1<<" ";
    if(((sum-1)/n+1)%2==1){
        cout<<((sum%n==0)?n:sum%n);
    }else{
        cout<<((sum%n==0)?1:n+1-sum%n);
    }
//    cout<<"\n"<<sum;            //for test,delete it!!!!!!!!!!!!
    return 0;
}
