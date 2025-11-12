#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,m;
string s1[N],s2[N],s,t;
bool check(string a,string b){
	for(int i=1;i<=a.size();i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		s=" "+s;
		t=" "+t;
		string a=s;
		string b=t;
		int cnt=0;
		for(int i=1;i<=n;i++){
			string c=s1[i];
			string d=s2[i];
			int step1=1,step2=step1+c.size()-1;
			while(step2<a.size()){
				bool f=0;
				int cntt=0;
				for(int j=step1;j<=step2;j++){
					if(a[j]!=c[cntt]){
						f=1;
					}
					cntt++;
				}
				if(f==0){
					cntt=0;
					for(int j=step1;j<=step2;j++){
						a[j]=d[cntt];
						cntt++;
					}
					if(check(a,b)){
						cnt++;
					}
					a=s;
				}
				step1++;
				step2++; 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
