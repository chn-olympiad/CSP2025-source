#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0;short f=1;char s=getchar();
	while(s<48||s>57){f=s=='-'?-1:1;s=getchar();}
	while(s>47&&s<58){x=x*10+(s&15);s=getchar();}
	return x*f;
}
const int N=2e5+5;
int n,q,ans;string s1[N],s2[N],t1,t2;
vector<int>nxt1[N],nxt2[N],e1,e2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		s1[i]=" ";s2[i]=" ";cin>>t1>>t2;s1[i]+=t1;s2[i]+=t2;
		for(int j=0;j<2;++j)nxt1[i].emplace_back(0);
		for(int j=0;j<2;++j)nxt2[i].emplace_back(0);
		for(int j=2,k=0;j<s1[i].size();++j){
			while(k&&s1[i][k+1]!=s1[i][j])k=nxt1[i][k];
			if(s1[i][k+1]==s1[i][j])++k;nxt1[i].emplace_back(k);
		}
		for(int j=2,k=0;j<s2[i].size();++j){
			while(k&&s2[i][k+1]!=s2[i][j])k=nxt2[i][k];
			if(s2[i][k+1]==s2[i][j])++k;nxt2[i].emplace_back(k);
		}
	}
	while(q--){
		s1[0]=" ";s2[0]=" ";cin>>t1>>t2;
		s1[0]+=t1;s2[0]+=t2;ans=0;
		e1.clear();e1.shrink_to_fit();
		e2.clear();e2.shrink_to_fit();
//		cout<<s1[0]<<'\n'<<s2[0]<<'\n';//
		for(int i=1,l1,l2;i<=n;++i){
			for(int j=2,k=0;j<=t1.size();++j){
				while(k&&s1[i][k+1]!=s1[0][j])k=nxt1[i][k];
				if(s1[i][k+1]==s1[0][j])++k;
				if(k==s1[i].size()-1)e1.emplace_back(j);
			}
			for(int j=2,k=0;j<=t2.size();++j){
				while(k&&s2[i][k+1]!=s2[0][j])k=nxt2[i][k];
				if(s2[i][k+1]==s2[0][j])++k;
				if(k==s2[i].size()-1)e2.emplace_back(j);
			}
//			for(int j:e1)cout<<j<<' ';cout<<'\n';//
//			for(int j:e2)cout<<j<<' ';cout<<'\n';//
			l1=0;l2=0;
			while(l1<e1.size()&&l2<e2.size()){
				if(e1[l1]==e2[l2]){++ans;++l1;++l2;}//bug,no time to fix
				else{
					if(e1[l1]<e2[l2])while(e1[l1]<e2[l2])++l1;
					else while(e1[l1]>e2[l2])++l2;
				}
				if(l1>=e1.size()||l2>=e2.size())break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//Usami Sumireko,Violet_Detector
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
//Ah,strings.
//Full_Speed said that strings can't be inserted into the exam.
//So this is the fact which means that he's wrong.
//Oh my Budhha...
//O(n*L2),KMP.
//Wait.My equal_check has bug.
//Ahh.
