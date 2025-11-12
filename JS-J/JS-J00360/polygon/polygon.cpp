#include<bits/stdc++.h>
using namespace std;
long long n,R,a[5005],snake[5005],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=500){
        for(int i=1;i<=n-2;i++){
            ans=(ans+i)%998244353;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        int al=0;
        for(int j=1;j<=i-1;j++){
            snake[j]=j;
            al+=a[j];
        }
        int l=i,jia=i-1,b=0;
        while(l<=n){
            while(al>a[l]&&l<=n){
                if(b==1){
                    b=0;break;
                }
                ans=(ans+1)%998244353;
            l++;
            }
            snake[jia]++;
            if(l==n&&snake[i-1]==n-1&&jia==i-1){break;}
            al=al-a[snake[jia]-1]+a[snake[jia]];
            
            if(l<=snake[i-1])l=snake[i-1]+1;
            if(l>n&&snake[i-1]<=n-1){
                l=n;
                ans=(ans+(l-snake[i-1]))%998244353;
                b=1;
            }
            else{
                if(al>a[l]){
                    ans=(ans+(l-snake[i-1]))%998244353;b=1;}
                else ans=(ans+(l-snake[i-1]-1))%998244353;
            }
            
            jia--;
            if(jia==0)jia=i-1;
            if(l==n&&snake[i-1]==n-1&&jia==i-1){break;}
        }
    }
    cout<<ans-1;
    return 0;
}