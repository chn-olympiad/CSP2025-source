#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define  fr first
#define sc second
#define int long long
const int N=2e5+10;
const int B=131,m=998244853;
int n,q,h[N][5],H[N][5],p[N],len[N][5];
string s[N][5],a,b;
int Hash(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=(ans*B%m+s[i]-'a'+1)%m;
    }return ans;
}
void Hsh(string s,int id){
    for(int i=1;i<=s.length();i++){
        H[i][id]=(H[i-1][id]*B%m+s[i]-'a'+1)%m;
    }
}
int qry(int id,int fr,int len){
    int ans=H[fr+len-1][id]-H[fr-1][id]*p[len]%m;
    ans=(ans%m+m)%m;return ans;
}
signed main(){
    p[0]=1;for(int i=1;i<=N-5;i++)p[i]=p[i-1]*B%m;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        len[i][0]=s[i][0].length();
        len[i][1]=s[i][1].length();
        h[i][0]=Hash(s[i][0]);
        h[i][1]=Hash(s[i][1]);
        // cout<<h[i][0]<<" "<<h[i][1]<<endl;
        // s[i][0]='0'+s[i][0];
        // s[i][1]='0'+s[i][1];
    }
    while(q--){
        cin>>a>>b;
        int cnt=0,la=a.length(),lb=b.length();
        if(la!=lb){printf("0\n");continue;}
        a='0'+a;b='0'+b;
        Hsh(a,0);Hsh(b,1);
        // for(int i=1;i<=la;i++){cout<<H[i][0]<<" ";}cout<<endl;
        // for(int i=1;i<=la;i++){cout<<H[i][1]<<" ";}cout<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j+len[i][0]-1<=la;j++){
                bool f_1=(qry(0,j,len[i][0])==h[i][0]);
                bool f_2=(qry(1,j,len[i][1])==h[i][1]);
                bool f_3=(qry(0,1,j-1)==qry(1,1,j-1));
                int ed=j+len[i][0]-1;
                bool f_4=(qry(0,ed+1,la-ed)==qry(1,ed+1,la-ed));
                if(f_1&&f_2&&f_3&&f_4){
                    cnt++;
                    // cout<<i<<" "<<j<<" "<<j+s[i][0].length()-1<<endl;
                }
            }
        }
        printf("%lld\n",cnt);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}