#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,rep,repp;
string s,ss;
ll kmp[1000000];
ll tr[2000000][26],cnt,sum[1000000];
ll tr1[2000000][26],cnt1,sum1[1000000],cntt;
void bui(){
	ll now=0;
	ll siz=s.size();
	for(int i=0;i<siz;i++){
		if(!tr[now][s[i]-'a']){
			tr[now][s[i]-'a']=++cnt;
		}
		now=tr[now][s[i]-'a'];
	}
	sum[now]=cntt;
}
void buii(){
	ll now=0;
	ll siz=ss.size();
	for(int i=0;i<siz;i++){
		if(!tr1[now][ss[i]-'a']){
			tr1[now][ss[i]-'a']=++cnt;
		}
		now=tr1[now][ss[i]-'a'];
	}
	sum1[now]=cntt;
}
ll doo(ll l,ll siz){
	ll now1=0,now2=0,ans=0,sizz=0;
	for(int i=l;i<=siz;i++){
		if(!tr[now1][s[i]-'a']||!tr1[now2][ss[i]-'a']){
			return ans;
		}
		sizz++;
		now1=tr[now1][s[i]-'a'],now2=tr1[now2][ss[i]-'a'];
//		cout<<i<<"**\n";
		if(i>=repp){
			if(sum[now1]!=0){
				ans+=(sum[now1]==sum1[now2]);
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>ss;	
		cntt++;
		bui();	
		buii();
	}
	for(int i=1;i<=q;i++){
		cin>>s;
		cin>>ss;
		ll siz=s.size();
		ll siz1=ss.size();
		if(siz==siz1){
			s=' '+s;
			ss=' '+ss;
			rep=repp=0;
			for(int j=siz;j>=1;j--){
				if(s[j]!=ss[j]){
					repp=j;
					break;
				}
			}
//			cout<<repp<<"*"<<endl;
			ll ls=0;
			for(int j=1;j<=siz;j++){
				ls+=doo(j,siz);
				if(s[j]!=ss[j]){
					break;
				}
			}
			cout<<ls<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
