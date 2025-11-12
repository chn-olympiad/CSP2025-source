#include<bits/stdc++.h>
using namespace std;
string s[200003],ss[200003];
int p[200003],pp[200003];
map<pair<string,string>,vector<int>> aa;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,p1=0,p2=0,cnt=0;
    cin>>n>>q;
    string tp,tp2,sq,ssq;
    for(int i=1; i<=n; i++){
        cin>>s[i]>>ss[i];
        if(s[i].size()!=ss[i].size())continue;
        tp="",tp2="",p1=0,p2=s[i].size()-1;
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]!=ss[i][j]){p1=j;break;}
        }for(int j=s[i].size()-1; j>=0; j--){
            if(s[i][j]!=ss[i][j]){p2=j;break;}
        }for(int j=p1; j<=p2; j++)tp+=s[i][j],tp2+=ss[i][j];
        //cout<<tp<<" "<<tp2<<endl;
        aa[make_pair(tp,tp2)].push_back(i),p[i]=p1,pp[i]=p2;
    }for(int i=1; i<=q; i++){
        cin>>sq>>ssq;
        tp="",tp2="",cnt=0,p1=0,p2=sq.size()-1;
        for(int j=0; j<sq.size(); j++){
            if(sq[j]!=ssq[j]){p1=j;break;}
        }for(int j=sq.size()-1; j>=0; j--){
            if(sq[j]!=ssq[j]){p2=j;break;}
        }for(int j=p1; j<=p2; j++)tp+=sq[j],tp2+=ssq[j];//cout<<tp<<" "<<tp2<<endl;
        for(auto j:aa[make_pair(tp,tp2)]){
            if(s[j].size()-p[j]>sq.size()-p1)goto ass;
            if(p[j]>p1)goto ass;
            for(int k=p[j]-1; k>=0; k--)if(s[j][k]!=sq[p1-p[j]+k]){goto ass;}//cout<<s[j]<<endl<<ss[j]<<endl;
            for(int k=pp[j]+1; k<s[j].size(); k++){
                //cout<<sq[p2+k-pp[j]];
                if(s[j][k]!=sq[p2+k-pp[j]]){goto ass;}
            }cnt++;
            //cout<<endl;
            ass:;
        }printf("%d\n",cnt);
    }return 0;
}
