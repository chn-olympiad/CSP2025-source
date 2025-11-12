#include<bits/stdc++.h>
#define int unsigned long long 
const int base=1e9+7;
using namespace std;
int n,q;
int len1;
int len2;
string a[100005],b[100005],kk[2005];
string t,tt;
string t1,t2;
int h1[100005],h2[100005],mi[100005];
map<pair<string,string>,int> mp,mp2;
int H(string s){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		char c=s[i]-'a'+1;
		cnt=cnt*base+c;
	}
	return cnt;
}
void H2(){
	for(int i=1;i<=len1;i++){
		char c=t1[i]-'a'+1;
		h1[i]=h1[i-1]*base+c;
	}
	for(int i=1;i<=len2;i++){
		char c=t2[i]-'a'+1;
		h2[i]=h2[i-1]*base+c;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<=100000;i++){
		mi[i]=mi[i-1]*base;
	}
	int mx=0,mx2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[{a[i],b[i]}]++;
		mx=max(mx,(int)a[i].size());
		mx2=max(mx2,(int)b[i].size());
	}
	for(int i=1;i<=2000;i++){
		kk[i]=kk[i-1]+'a';
	}
	while(q--){
		cin>>t1>>t2;
		len1=t1.size();
		len2=t2.size();
		t1=" "+t1;
		t2=" "+t2;
		if(len1<=2000){
			H2();
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i].size()>len1)continue;
				int c1=H(a[i]);
				int c2=H(b[i]);
				int l=a[i].size();
				for(int j=1;j<=len1;j++){
					if(j+l-1>len1)continue;
					int cc=h1[j+l-1]-(mi[l]*h1[j-1]);
					int cc2=h2[j+l-1]-(mi[l]*h2[j-1]);
					int u1=h1[j-1],u2=h2[j-1];
					int v1=0,v2=0;
					if(j+l-1<len1)v1=h1[len1]-h1[j+l-1]*mi[len1-(j+l-1)],v2=h2[len1]-h2[j+l-1]*mi[len1-(j+l-1)];
					if(c1==cc&&c2==cc2&&u1==u2&&v1==v2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}else{
			int op=0;
			int val1=0,val2=0;
			for(int i=1;i<=len1;i++){
				if(t1[i]=='b'){
					val1=i;
					break;
				}
			}
			for(int i=1;i<=len1;i++){
				if(t2[i]=='b'){
					val2=i;
					break;
				}
			}
			if(val1>val2)swap(val1,val2);
			int sz=val2-val1+1;
			t=t1.substr(val1,sz);
			tt=t2.substr(val1,sz);
			for(int i=1;i<=min((int)mx,(int)mx2)-t.size();i++){
				string s=kk[i]+t;
				string s2=kk[i]+tt;
				for(int j=1;j<=min((int)mx,(int)mx2)-t.size();j++){
					s+=kk[j];
					s2+=kk[j];
					if(mp[{s,s2}]>0){
						op+=mp[{s,s2}];
					}
				}
			}
			cout<<op<<endl;
		}
	}
		
	return 0;
}