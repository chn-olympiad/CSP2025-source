#include<iostream>
using namespace std;
int n,a[5005];
long long ans;
bool one=1;
//int A(int x,int y){
//}
long long C(int x,int y){
    if(x-y<y) return C(x,x-y);
    long long ans=1;
    for(int i=1,p=x;i<=y;i++,p--){
        ans*=p;
        ans/=i;
        ans%=998244353;
    }
    return ans;
}
void DFS(int k,int t,int mx,int he){
    if(k>n){
        if(t>=3){
            if(he-2*mx>0){
                //cout<<t<<endl;
                ans++;
                ans%=998244353;
            }
        }
        return;
    }
    DFS(k+1,t+1,max(mx,a[k]),he+a[k]);
    DFS(k+1,t,mx,he);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) one=0;
    }
    if(n<3){
        cout<<0<<endl;
        return 0;
    }else if(n==3){
        int x=a[1]+a[2]+a[3],y=2*max(max(a[1],a[2]),a[3]);
        if(x>y) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }else if(one){
        for(int i=3;i<=n;i++){
            ans+=C(n,i);
            ans%=998244353;
        }
        ans%=998244353;
        cout<<ans<<endl;
    }else{
        //for(int i=1;i<=n;i++){
        //    for(int j=i;j<=n;j++){
        //        mx[i][j]=max(mx[i][j-1],a[j]);
        //        he[i][j]=he[i][j-1]+a[j];
        //    }
        //}
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=n;j++){
        //        cout<<mx[i][j]<<' ';
        //    }
        //    cout<<endl;
        //}
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=n;j++){
        //        cout<<he[i][j]<<' ';
        //    }
        //    cout<<endl;
        //}
        DFS(1,0,0,0);
        ans%=998244353;
        cout<<ans;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
