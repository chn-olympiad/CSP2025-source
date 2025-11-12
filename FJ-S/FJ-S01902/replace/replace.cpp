#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long 
int n,q;
string s1,s2,t1,t2;
int ans;
map<string,string> mp;
map<string,bool> ma;
int suf,sub,sff[N][2],sbb[N][2];
vector<int> bj[100005][2][2];
void solve(){
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
			if(s1[j]=='b') {suf+=j,sub+=n-j-1;break;sbb[j][0]=j,sff[j][0]=n-j-1;} 					
		for(int j=0;j<s2.size();j++)
			if(s2[j]=='b') {suf-=j,sub-=n-j-1;break;sbb[j][1]=j,sff[j][1]=n-j-1;} 
		if(suf<0) bj[suf][0][0].push_back(i);
		else bj[suf][0][1].push_back(i);
		if(sub<0) bj[sub][1][0].push_back(i);
		else bj[sub][1][1].push_back(i);		
	}
//	cout<<"fgvdsfdf\n";
	while(q--){
		cin>>t1>>t2;
		int us1=0,us2=0,ub1=0,ub2=0,cnt=0,zh=0;
		for(int j=0;j<t1.size();j++)
			if(t1[j]=='b') {suf+=j,sub+=n-j-1;break;}  		
		for(int j=0;j<t2.size();j++)
			if(t2[j]=='b') {suf+=j,sub+=n-j-1;break;} 
		int flag1=1,flag2=1;
		if(suf<0) flag1=0,suf=-suf;
		if(sub<0) flag2=0,sub=-sub;
		for(int i=0;i<bj[suf][flag1][0].size();i++){
			for(int j=zh;j<bj[sub][flag2][1].size();j++){
				if(bj[suf][flag1][0][i]==bj[sub][flag2][1][j]) cnt++;
			}
		} 
		cout<<cnt<<'\n';		
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	cin>>n>>q;
//	if(n>200&&q!=1||(n<=2000&&q==1&&n>200)){
		solve();
		return 0;
//	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2,ma[s1]=1;
	}
	while(q--){
		cin>>t1>>t2;ans=0;
		for(int i=0;i<t1.size();i++){
			string ss="";
			for(int j=0;j<i;j++) ss+=t1[j];
			for(int j=1;i+j-1<=t1.size();j++){
				string th="";							
				for(int k=i;k<=i+j-1;k++)
					th+=t1[k];
//				cout<<th<<' '<<ss<<'\n';
				if(ma[th]==1) th=mp[th];
				else continue;
				string tt=ss;tt+=th;
				for(int k=i+j;k<t1.size();k++)
					tt+=t1[k];
//				cout<<"tt:"<<tt<<t2<<'\n';
				bool flag=1;if(tt.size()!=t2.size()) continue;
				for(int i=0;i<=tt.size();i++){
					if(tt[i]!=t2[i]){flag=0;break;}
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}








