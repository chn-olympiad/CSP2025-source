#include<bits/stdc++.h>
#define ull unsigned long long
#define fi first
#define se second
using namespace std;

const int N=2e5+10,M=5e6+10;
int n,q;
string s[N][2],t[N][2];
char str[M];
vector<ull>H[N];
ull pw[M],sh[N][2],th[N];

ull gt(int i,int l,int r){
    return H[i][r]-H[i][l-1]*pw[r-l+1];
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        int l;
        scanf("%s",str+1);
        l=strlen(str+1);
        s[i][0]="+";
        for(int j=1;j<=l;j++)s[i][0].push_back(str[j]);

        scanf("%s",str+1);
        l=strlen(str+1);
        s[i][1]="+";
        for(int j=1;j<=l;j++)s[i][1].push_back(str[j]);

        for(int j=0;j<2;j++)
            for(int k=1;k<=l;k++)
                sh[i][j]=13331*sh[i][j]+s[i][j][k]-'a'+1;
        // cout<<s[i][0]+" "+s[i][1]+"\n";
    }
    for(int i=1;i<=q;i++){
        int l;
        scanf("%s",str+1);
        l=strlen(str+1);H[i].resize(l+5,0);
        t[i][0]="+";
        for(int j=1;j<=l;j++)t[i][0].push_back(str[j]);

        scanf("%s",str+1);
        l=strlen(str+1);
        t[i][1]="+";
        for(int j=1;j<=l;j++)t[i][1].push_back(str[j]);

        if(t[i][0].size()==t[i][1].size()){
            for(int k=1;k<=l;k++)
                H[i][k]=13331*H[i][k-1]+t[i][0][k]-'a'+1,
                th[i]=13331*th[i]+t[i][1][k]-'a'+1;
        }
        // cout<<t[i][0]+" "+t[i][1]+"\n";
    }
    pw[0]=1;
    for(int i=1;i<=5e6;i++)pw[i]=pw[i-1]*13331;

    for(int i=1;i<=q;i++)if(t[i][0].size()==t[i][1].size()){
        bool b=0;int ans=0;
        int l,r;
        for(int j=1;j<t[i][0].size();j++)if(t[i][0][j]!=t[i][1][j]){l=j;break;}
        for(int j=t[i][0].size()-1;j>=1;j--)if(t[i][0][j]!=t[i][1][j]){r=j;break;}
        if(l<=t[i][0].size()-r){
            for(int j=1;j<=l;j++)
                for(int k=1;k<=n;k++){
                    int len=s[k][0].size()-1;
                    if(j+len-1<t[i][0].size()&&sh[k][0]==gt(i,j,j+len-1)){
                        ull h=H[i][j-1]*pw[len]+sh[k][1];
                        h=h*pw[t[i][0].size()-j-len]+gt(i,j+len,t[i][0].size()-1);//ntc
                        if(h==th[i])ans++;
                    }
                }
        }else{
            for(int j=t[i][0].size()-1;j>=r;j--)
                for(int k=1;k<=n;k++){
                    int len=s[k][0].size()-1;
                    if(j-len+1>=1&&sh[k][0]==gt(i,j-len+1,j)){
                        ull h=H[i][j-len]*pw[len]+sh[k][1];
                        h=h*pw[t[i][0].size()-j-1]+gt(i,j+1,t[i][0].size()-1);//ntc
                        if(h==th[i])ans++;
                    }
                }
        }
        printf("%d\n",ans);
    }else puts("0");
    return 0;
}