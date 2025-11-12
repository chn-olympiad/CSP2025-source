//luogu uid: 1411407  yyc_Yae_Miko(blue(???) name)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
using namespace std;
int rd(){
    int x=0,f=1;char c;
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-'){f=-1;c=getchar_unlocked();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c&15);c=getchar_unlocked();}
    return x*f;
}
int a[102],pos;
int s[15][15];
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    //freeopen("seat.in","r",stdin);
    //freeopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);//How water the problem is...
    int n=rd(),m=rd();
    for(int i=1;i<=n*m;i++)a[i]=rd();
    int x=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++){
                s[i][j]=a[++pos];//useless...
                if(x==a[pos]){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }else{
            for(int i=n;i>=1;i--){
                s[i][j]=a[++pos];//useless...
                if(x==a[pos]){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
