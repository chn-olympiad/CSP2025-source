#include<iostream>
using namespace std;
long long s,q,ans,s1b[200001],s2b[200001],q1b[200001],q2b[200001],lens[200001],lenq[200001],qzh[200001];
string s1[200001],s2[200001],q1[200001],q2[200001];
int qlen[500001],slen[500001],ql[500001],qr[500001],sl[500001],sr[500001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>s>>q;
    for(int i=1;i<=s;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>q1[i]>>q2[i];
    }
    if((s*q<=100000000)){
        for(int i=1;i<=q;i++){
            qlen[i]=q1[i].size();
            for(int j=0;j<qlen[i];j++){
                if(q1[i][j]!=q2[i][j])qr[i]=j;
            }
            for(int j=qlen[i]-1;j>=0;j--){
                if(q1[i][j]!=q2[i][j])ql[i]=j;
            }
        }
        for(int i=1;i<=s;i++){
            slen[i]=s1[i].size();
            for(int j=0;j<slen[i];j++){
                if(s1[i][j]!=s2[i][j])sr[i]=j;
            }
            for(int j=slen[i]-1;j>=0;j--){
                if(s1[i][j]!=s2[i][j])sl[i]=j;
            }
        }
        for(int i=1;i<=q;i++){
            ans=0;
            for(int j=1;j<=s;j++){
                int bo=0;
                if(sr[j]-sl[j]==qr[i]-ql[i]){
                    if(ql[i]>=sl[j]){
                        if(qlen[i]-qr[i]>=slen[j]-sr[j]){
                            bo=1;
                            int cw=ql[i]-sl[j];
                            for(int o=0;o<slen[j];o++){
                                if(s1[j][o]!=q1[i][o+cw])bo=0;
                                if(s2[j][o]!=q2[i][o+cw])bo=0;
                            }
                        }
                    }
                }
                ans+=bo;
            }
            cout<<ans<<endl;
        }
    }
    else{
        for(int i=1;i<=s;i++){
            int le=s1[i].size();
            for(int j=0;j<le;j++)if(s1[i][j]=='b')s1b[i]=j;
            for(int j=0;j<le;j++)if(s2[i][j]=='b')s2b[i]=j;
        }
        for(int i=1;i<=q;i++){
            int le=q1[i].size();
            for(int j=0;j<le;j++)if(q1[i][j]=='b')q1b[i]=j;
            for(int j=0;j<le;j++)if(q2[i][j]=='b')q2b[i]=j;
        }
        for(int i=1;i<=s;i++)qzh[s2b[i]-s1b[i]]++;
        for(int i=1;i<=q;i++)cout<<qzh[q2b[i]-q1b[i]]<<endl;
    }
    return 0;
}