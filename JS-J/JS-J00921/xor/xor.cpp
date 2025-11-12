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
int a[500005];
int s[500005];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    //freeopen("xor.in","r",stdin);
    //freeopen("xor.out","w",stdout);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);//How difficulty the problem is...
    int n=rd(),k=rd();
    for(int i=1;i<=n;i++){
        a[i]=rd();
        s[i]=s[i-1]^a[i];
    }
    int pos=1;
    int ans=0;
    /*
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<(s[j]^s[i-1])<<' ';
        }
    }
    */
    for(int i=1;i<=n;i++){
        if(pos>i)continue;
        for(int j=pos;j<=i;j++){
            if(pos>j)continue;
            if((s[j]^s[pos-1])==k){
                pos=j+1;
                ans++;
                //cout<<i<<' '<<j<<'\n';
            }else if((s[i]^s[j-1])==k){
                pos=i+1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//while(1)whr's rp--;
//bool whr_will_all_WA_csp(){return ture}
