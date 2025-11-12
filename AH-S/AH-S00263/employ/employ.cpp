#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
bool fa=1;
int a[505],c[505],l[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=i;
        if(s[i]=='0')fa=0;
    }
    if(fa==1&&n>=40){
        int t=0;
        ans=1;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                t++;
            }
        }
        for(int i=t-m+1;i<=t;i++){
            ans*=i;
            ans=ans%998244353;
        }
        cout<<ans;
        return 0;
    }
    do{
        int sum=0,b=0;
        for(int i=1;i<=n;i++){
            c[l[i]]=a[i];
        }
        for(int i=1;i<=n;i++){
            if(b>=c[i]){
                b++;
            }else if(s[i]=='1'){
                sum++;
            }else if(s[i]=='0'){
                b++;
            }
        }
        if(sum>=m){
            ans++;
            ans=ans%998244353;
        }
        /*for(int i=1;i<=n;i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
        cout<<sum<<endl;*/
    }while(next_permutation(l+1,l+1+n));
    cout<<ans;
    return 0;
}
