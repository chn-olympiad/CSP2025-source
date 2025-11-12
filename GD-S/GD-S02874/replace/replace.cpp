#include<bits/stdc++.h>
using namespace std;
struct eyc{
	string s1,s2;
}a[200005];
bool rpl(string x,string y,int ch){
	string bf="",af="";
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i]){
			bf+=x[i];
			af+=y[i];
		}
	}
	string sbf="",saf="";
	for(int i=0;i<a[ch].s1.size();i++){
		if(a[ch].s1[i]!=a[ch].s2[i]){
			sbf+=a[ch].s1[i];
			saf+=a[ch].s2[i];
		}
	}
	return ((bf==sbf)&&(af==saf));
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=0;i<q;i++){
		string ss1,ss2;
		int ans=0;
		cin>>ss1>>ss2;
		for(int j=0;j<n;j++){
			if(rpl(ss1,ss2,j)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
