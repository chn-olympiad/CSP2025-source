#include<bits/stdc++.h>
using namespace std;
int n,q;
string a1[200010],a2[200010];
string s1,s2;
string ss,st;
int x;
string sss;
void tihuan(){
	int t=sss.find(ss);
	string ss1=sss.substr(0,t);
	string ss2=sss.substr(t,t+ss.size());
	string ss3=sss.substr(t+ss.size(),sss.size()-1);
	sss=ss1+st+ss3;
}
int geshu(){
	int anss=0,l=s1.size();
	for(int i=0;i<l;i++){
		string sst=s1.substr(0,i);
		sss=s1.substr(i,l);
		int t=sss.find(ss);
		if(t==-1)break;
		else {
			tihuan();
			if(sst+sss==s2){
				anss++;
				i=t+ss.size()+sst.size();
			}
		}
	}
	return anss;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		if(ss1!=ss2)a1[++x]=ss1,a2[x]=ss2;
	}
	while(q--){
		cin>>s1>>s2;
		int ans=0;
		if(s1.size()!=s2.size()){cout<<0<<endl;continue;}
		for(int i=1;i<=x;i++){
			ss=a1[i],st=a2[i];
			if(ss==s1&&st==s2)ans++;
			else ans+=geshu();
		}
		cout<<ans<<endl;
	}
}
