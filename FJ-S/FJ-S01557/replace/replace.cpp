#include<bits/stdc++.h>
using namespace std;
struct D{
	string s1,s2;
}xy[200005];
string shachu(string &s){
	string t="";
	for(int i=0;i<s.size();++i){
		if(s[i]!='#') t+=s[i];
	}
	return t;
}
long long hash(string s){
	long long base=133,price=11451717,ans=0;
	for(int i=0;i<s.size();++i){
		ans+=base*(ans+s[i])+price;
	}
	return ans;
}
bool check(string s,string t){
	if(hash(s)!=hash(t)) return false;
	else return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>xy[i].s1>>xy[i].s2;
		int S=xy[i].s1.size();
		for(int j=0;j<S;++j){
			if(xy[i].s1[j]==xy[i].s2[j]) xy[i].s1[j]=xy[i].s2[j]='#';
		}
		xy[i].s1=shachu(xy[i].s1);xy[i].s2=shachu(xy[i].s2);
	}
	for(int i=1;i<=q;++i){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int S=t1.size();
		for(int j=0;j<S;++j){
			if(t1[j]==t2[j]) t1[j]='#',t2[j]='#';
		}
		t1=shachu(t1);t2=shachu(t2);
		for(int j=1;j<=n;++j){
			if(check(t1,xy[j].s1)==true&&check(t2,xy[j].s2)==true) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
