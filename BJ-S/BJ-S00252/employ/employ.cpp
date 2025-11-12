#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::next_permutation;
using std::string;
#define MAXN 503
#define MOD 998244353
int a[MAXN],n,m,c[MAXN];
bool flag[MAXN];
long long ans;
string d;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)   cin>>c[i],a[i]=i;
    if(d.find('0')==string::npos&&n>18){
        //calc n!
        ans=1;
        for(int i=2;i<=n;i++)    ans=(ans*i)%MOD;
        cout<<ans<<endl;
        return 0;
    }
    do{
        int cnt=0,cnt2=0,i;
        for(i=1;i<=n;i++){
            if(cnt>=c[a[i]]){
                cnt++;
                continue;
            }
            if(d[i-1]=='0'){
                cnt++;
            } else {
                cnt2++;
            }
            if(cnt2>=m){ans=(ans+1)%MOD;break;}
        }
        if(cnt2>=m){
            memset(flag,0,sizeof(flag));
            for(int j=1;j<=i;j++)   flag[a[j]]=1;
            long long ad=1;
            for(int j=2;j<=n-i;j++) ad=ad*j%MOD;
            ans=(ans+ad-1)%MOD;
            for(int j=i+1;j<=n;j++)
                for(int k=n;k>=1;k--)
                    if(!flag[k]){
                        a[j]=k;
                        flag[k]=1;
                        break;
                    }
        }
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<endl;
    return 0;
}
