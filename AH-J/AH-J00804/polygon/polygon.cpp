#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 5005
#define mod 998244353
using namespace std;
typedef long long ll;
int n,a[MAXN],b[MAXN],t[MAXN];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(int i=1;i<=5000;i++){
        t[i]=t[i-1]+b[i];
    }
    sort(a+1,a+n+1);
    if(n<=2){
        cout<<0;
        return 0;
    }else if(n==3){
        if(a[3]-a[1]<a[2]&&a[1]+a[3]>a[2]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n==4){
        int cnt=0,a1=a[1],a2=a[2],a3=a[3],a4=a[4];
        cnt+=(a3-a1<a2&&a3+a1>a2)+(a4-a1<a2&&a4+a1>a2)+(a2-a4<a3&&a2+a4>a3)+(a1+a2+a3+a4>2*a4);
        cout<<cnt;
    }else if(n==5){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt+=t[a[i]+a[j]-1]-t[a[i]-a[j]];
            }
        }
        cnt+=(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int h=k+1;h<=n;h++){
                        if(i+j+k+h>2*h){
                            cnt++;
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//#Shang4Shan3Ruo6Shui4
