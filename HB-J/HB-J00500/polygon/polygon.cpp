#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],book[5005],flag=0;
const long long Y=998244353;
long long cnt;
void dfs(int x,int last){
    if(x==0){
        int maxi;
        long long cnt1=0;
        for(int i=0;i<=n;i++){
            if(book[i]==1){
                maxi=i;
                cnt1+=a[i];
            }
        }
        if(cnt1>(2*a[maxi])){
            cnt++;
            cnt%=Y;
        }
        return;
    }
    for(int i=last;i<=n-x;i++){
        if(book[i]==1){
            continue;
        }
        book[i]=1;
        dfs(x-1,i+1);
        book[i]=0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=1;
        }
    }
    if(flag==0){
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                cnt+=((1+j)*j)/2;
                cnt%=Y;
            }
        }
        cout<<cnt;
    }
    else{
        sort(a,a+n);
        for(int i=3;i<=n;i++){
            dfs(i,0);
        }
        cout<<cnt;
    }
    return 0;
}