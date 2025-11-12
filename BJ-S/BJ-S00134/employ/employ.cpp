#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;const ll mod=998244353;
int n,m,a[N],c[N];ll genshin=0;
struct K_1{
    int p[N];
    bool check(){return n<=10;}
    bool pan(){int cnt=0;
        for(int i=1;i<=n;i++){
            if(c[p[i]]>(i-1)-cnt&&a[i]==1)cnt++;
        }
        //if(cnt<m)cout<<"SDF";
        return cnt>=m;
    }
    void work(){
        for(int i=1;i<=n;i++)p[i]=i;genshin+=pan();
        while(next_permutation(p+1,p+n+1)){genshin+=pan();}
    }
}T1;
struct K_2{
    bool check(){for(int i=1;i<=n;i++)if(a[i]==0)return 0;return 1;}
    void work(){int cnt=n;
        for(int i=1;i<=n;i++){
            if(c[i]==0)cnt--;
        }
        if(cnt<m){genshin=0;}
        else{
            genshin=1;for(int i=1;i<=n;i++)genshin=genshin*i%mod;
        }
    }
}T2;
struct K_3{
    ll fac[N];
    bool check(){int cnt=0;for(int i=1;i<=n;i++)if(a[i]==1)cnt++;return cnt<=18;}
    void work(){
        sort(c+1,c+n+1);fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
        int cnt=0,b[20];for(int i=1;i<=n;i++)if(a[i]==1)b[++cnt]=i;
        if(cnt<m){genshin=0;return;}
        for(int st=0;st<(1<<cnt);st++){
            ll sum=1;
            vector<int>tmp1,tmp2;
            for(int i=1;i<=cnt;i++){
                if((st>>i-1)&1){
                       // cout<<b[i]<<' ';
                    //int qian=b[i]-1-tmp.size();
                    tmp1.push_back(b[i]-1-(int)tmp1.size());//没被录取
                }
                else{
                    tmp2.push_back(b[i]-1-(int)tmp1.size());//没被录取
                }
            }if(tmp1.size()<m)continue;
            reverse(tmp1.begin(),tmp1.end());
            for(int i=0;i<tmp1.size();i++){
                int j=upper_bound(c+1,c+n+1,tmp1[i])-c;
                //cout<<c[j-1]<<' '<<c[j]<<' '<<tmp[i]<<endl;
                if(n-j+1-i<=0){sum=0;break;}//GG
                sum=sum*(n-j+1-i)%mod;
            }
            sum*=fac[n-(int)tmp1.size()];genshin=(genshin+sum%mod)%mod;
        }
    }
}T3;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;for(int i=1;i<=n;i++){
        char c;cin>>c;a[i]=(int)(c-'0');//a[i]^=1;a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    if(T1.check()){T1.work();cout<<(genshin%mod+mod)%mod<<endl;return 0;}
    if(T2.check()){T2.work();cout<<(genshin%mod+mod)%mod<<endl;return 0;}
    if(T3.check()){T3.work();cout<<(genshin%mod+mod)%mod<<endl;return 0;}
    return 0;
}
//5 2
//11101
//6 0 4 2 1
//4 2
//1110
//6 0 4 2
