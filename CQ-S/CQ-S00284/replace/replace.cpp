#include<bits/stdc++.h>
#define N 200005
#define b1 1331
#define b2 131
#define b3 11451
#define M 5000005
#define ull unsigned long long
using namespace std;
int newch,n,q;
ull Hash[M],B1[M],B3[M],Hash3[M];
map<pair<ull,ull>,int>spc;
map<pair<int,int>,vector<pair<pair<ull,ull>,pair<int,int>>>> Map;
inline void init(string &s1,string &s2){
	if(s1==s2){
		return;
	}
    int tp=-1,bak=s1.size();
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            tp=i-1;break;
        }
    }
    for(int i=int(s1.size())-1;i>=0;i--){
        if(s2[i]!=s1[i]){
            bak=i+1;break;
        }
    }
    ull spc1=0,spc2=0,spc11=0,spc22=0;
    for(int i=tp+1;i<bak;i++){
        spc1=spc1*b2+s1[i]-'a';
        spc2=spc2*b2+s2[i]-'a';
        spc11=spc11*b3+s1[i]-'a';
        spc22=spc22*b3+s2[i]-'a';
    }
    if(!spc[make_pair(spc1,spc11)]){
        spc[make_pair(spc1,spc11)]=++newch;
    }spc1=spc[make_pair(spc1,spc11)];
    if(!spc[make_pair(spc2,spc22)]){
        spc[make_pair(spc2,spc22)]=++newch;
    }spc2=spc[make_pair(spc2,spc22)];
//    cout<<tp+1<<" to "<<bak-1<<" is "<<spc1<<' '<<spc2<<endl;
    ull r1=0,r2=0;
    for(int i=0;i<s1.size();i++){
        r1=r1*b1+s1[i];
        r2=r2*b3+s1[i];
    }
    Map[make_pair(spc1,spc2)].push_back(make_pair(make_pair(r1,r2),make_pair((int)(s1.size()),tp+1)));
}
inline ull getHash(int l,int r){
    if(l<0){
        return 0;
    }
    if(l==0){
        return Hash[r];
    }return Hash[r]-Hash[l-1]*B1[(r-l+1)];
}
inline ull getHash3(int l,int r){
    if(l<0){
        return 0;
    }
    if(l==0){
        return Hash3[r];
    }return Hash3[r]-Hash3[l-1]*B3[(r-l+1)];
}
inline void get(string &s1,string &s2){
	if(s1.size()!=s2.size()){
		cout<<0<<endl;return;
	}
    int tp=-1,bak=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            tp=i-1;break;
        }
    }
    for(int i=int(s1.size())-1;i>=0;i--){
        if(s2[i]!=s1[i]){
            bak=i+1;break;
        }
    }
    ull spc1=0,spc2=0,spc11=0,spc22=0;
    for(int i=tp+1;i<bak;i++){
        spc1=spc1*b2+s1[i]-'a';
        spc2=spc2*b2+s2[i]-'a';
        spc11=spc11*b3+s1[i]-'a';
        spc22=spc22*b3+s2[i]-'a';
    }
    if(!spc[make_pair(spc1,spc11)]){
        spc[make_pair(spc1,spc11)]=++newch;
    }spc1=spc[make_pair(spc1,spc11)];
    if(!spc[make_pair(spc2,spc22)]){
        spc[make_pair(spc2,spc22)]=++newch;
    }spc2=spc[make_pair(spc2,spc22)];
    for(int i=0;i<s1.size();i++){
        if(i==0){
            Hash[i]=s1[i];
        }else{
            Hash[i]=s1[i]+Hash[i-1]*b1;
        }
        if(i==0){
            Hash3[i]=s1[i];
        }else{
            Hash3[i]=s1[i]+Hash3[i-1]*b3;
        }
    }int ret=0;
    for(auto&v:Map[make_pair(spc1,spc2)]){
        ull h1=v.first.first;ull h3=v.first.second;
		int len=v.second.first,tp1=v.second.second;
		if(tp-tp1+1+len-1>=s1.size()){
//			cout<<"Yes";
			continue;
		}
        if(getHash(tp-tp1+1,tp-tp1+1+len-1)==h1&&getHash3(tp-tp1+1,tp-tp1+1+len-1)==h3){
            ret++;
        }
    }cout<<ret<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    cin>>n>>q;B1[0]=1;B3[0]=1;
    for(int i=1;i<M;i++){
        B1[i]=B1[i-1]*b1;
        B3[i]=B3[i-1]*b3;
    }
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;init(s1,s2);
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;get(t1,t2);
    }
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
