#include<bits/stdc++.h>
using namespace std;
struct nn{
	string s1,s2;
	int len;
}a[200001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2,a[i].len=a[i].s1.size();
	while(q--){
		int ans=0;
		string s,t;
		cin>>s>>t;
		int lens=s.size(),lent=t.size();
		for(int i=0;i<lens;i++){
			string s1=s;
			for(int j=1;j<=n;j++){
				string s2=s1.substr(i,a[j].len);
				if(s2==a[j].s1) s1=s1.replace(i,a[j].len,a[j].s2);
				if(s1==t)
					ans++;
				s1=s;
			}
		}
		cout<<ans<<'\n';
		
	}
}
