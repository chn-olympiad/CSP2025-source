#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a==b){
			cout<<0<<"\n";
			continue;
		}
		int m=a.size();
		a="~"+a;
		b="~"+b;
		int cnt=0;
		for(int i=1;i<=m;++i){
			for(int j=i;j<=m;++j){
				string s;
				for(int l=i;l<=j;++l){
					s+=a[l];
				}
				if(mp.count(s)==true){
					string s1,s2;
					for(int l=0;l<i;++l){
						s1+=a[l];
					}
					for(int l=j+1;l<=m;++l){
						s2+=a[l];
					}
					string ss=mp[s];
					a=s1+ss+s2;
					cnt++;
				}
			}
		}
		if(a!=b)cnt=0;
		cout<<cnt<<"\n";
	}
	return 0;
}
