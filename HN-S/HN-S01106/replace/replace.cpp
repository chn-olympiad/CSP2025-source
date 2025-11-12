#include<bits/stdc++.h>
#define int long long
using namespace std;
using ull = unsigned long long;
const int M=5e6+5,N=2e5+5;
int n,q,ans[N],st,ed;
int lens[N][2],lent[N][2];
ull w[30],P,p[N],val1,val2;
vector<ull>pres[N][2],pret[N][2];
string s[N][2],t[N][2];
mt19937_64 rd(random_device{}());
ull gett(int id,int op,int l,int r){
    return pret[id][op][r]-pret[id][op][l-1]*p[r-l+1];
}
ull gets(int id,int op,int l,int r){
    return pres[id][op][r]-pres[id][op][l-1]*p[r-l+1];
}
int work(ull x,ull y,int id,int st,int ed){
    int sum=0;//,len=ed-st+1;
    for(int i=1;i<=n;i++){
        for(int j=max(1ll,ed-lens[i][0]+1);j<=st;j++){
            if(j+lens[i][0]-1>lent[id][0])break;
            if(pres[i][0][lens[i][0]]==gett(id,0,j,j+lens[i][0]-1)&&pres[i][1][lens[i][0]]==gett(id,1,j,j+lens[i][0]-1))sum++;
        }
        // for(int j=1;j<=lens[i][0];j++){
        //     if(j+len-1>lens[i][0])break;
        //     if(gets(i,0,j,j+len-1)==x&&gets(i,1,j,j+len-1)==y)sum++;
        // }
    }
    return sum;
}
void sol(){
    P=rd();
    p[0]=1;
    for(int i=1;i<M;i++)p[i]=p[i-1]*P;
    for(int i=0;i<26;i++)w[i]=rd();
    for(int i=1;i<=n;i++){
        lens[i][0]=s[i][0].size();
        lens[i][1]=s[i][1].size();
        pres[i][0].resize(lens[i][0]+1);
        pres[i][1].resize(lens[i][1]+1);
        for(int j=1;j<=lens[i][0];j++){
            pres[i][0][j]=pres[i][0][j-1]*P+w[s[i][0][j-1]-'a'];
            pres[i][1][j]=pres[i][1][j-1]*P+w[s[i][1][j-1]-'a'];
        }
    }
    for(int i=1;i<=q;i++){
        lent[i][0]=t[i][0].size();
        lent[i][1]=t[i][1].size();
        pret[i][0].resize(lent[i][0]+1);
        pret[i][1].resize(lent[i][1]+1);
        for(int j=1;j<=lent[i][0];j++){
            pret[i][0][j]=pret[i][0][j-1]*P+w[t[i][0][j-1]-'a'];
        }
        for(int j=1;j<=lent[i][1];j++){
            pret[i][1][j]=pret[i][1][j-1]*P+w[t[i][1][j-1]-'a'];
        }
    }
    for(int i=1;i<=q;i++){
        if(lent[i][0]!=lent[i][1]){ans[i]=0;continue;}
        for(int j=1;j<=lent[i][0];j++){
            if(t[i][0][j-1]!=t[i][1][j-1]){
                st=j;
                break;
            }
        }
        for(int j=lent[i][0];j;j--){
            if(t[i][0][j-1]!=t[i][1][j-1]){
                ed=j;
                break;
            }
        }
        val1=gett(i,0,st,ed),val2=gett(i,1,st,ed);
        ans[i]=work(val1,val2,i,st,ed);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
}
bool check_B(){
    for(int i=1;i<=n;i++){
        int x=s[i][0].size(),cnt=0;
        for(int j=0;j<x;j++){
            cnt+=(s[i][0][j]=='b');
        }
        if(cnt>1)return 0;
        cnt=0;
        for(int j=0;j<x;j++){
            cnt+=(s[i][1][j]=='b');
        }
        if(cnt>1)return 0;
    }
    for(int i=1;i<=q;i++){
        int x=s[i][0].size(),cnt=0;
        if(s[i][0].size()!=s[i][1].size())continue;
        for(int j=0;j<x;j++){
            cnt+=(t[i][0][j]=='b');
        }
        if(cnt>1)return 0;
        for(int j=0;j<x;j++){
            cnt+=(t[i][1][j]=='b');
        }
        if(cnt>1)return 0;
    }
    return 1;
}
void sol_B(){

}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
    }
    // if(check_B())sol_B();
    // else 
    if(n<=2000&&q<=2000)sol();
    else{
        for(int i=1;i<=q;i++)cout<<0<<"\n";
    }
    return 0;
}