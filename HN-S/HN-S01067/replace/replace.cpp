#include <bits/stdc++.h>
using namespace std;
string pa[200005][2];
map<string,int> mp;
int main(){
	int n,q;
	cin>>n>>q;
	char x;
	int minl=0x3f3f3f,minr=0x3f3f3f;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1;
		for(int j=1;j<=s1.length();j++){
			cin>>x;
			s2=s2+x;
		}
		mp[s1]=i;
		mp[s2]=i;
		pa[i][0]=s1;
		pa[i][1]=s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		
		if(mp[t1]==mp[t2] && mp[t1]!=0){
			cout<<1<<endl;
			return 0;
		}
		for(int i=1;i<=t1.length();i++)
		{
			if(t1[i-1]=='b'){
				int l,r;
				l=i-1;
				r=t1.size()-i;
				minl=min(l,minl);
				minr=min(r,minr);
			}
		}
		for(int i=1;i<=t2.length();i++)
		{
			if(t2[i-1]=='b'){
				int l,r;
				l=i-1;
				r=t2.size()-i;
				minl=min(l,minl);
				minr=min(r,minr);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bool f=true;
			for(int i=1;i<=pa[i][0].length();i++)
			{
				int l,r;
				if(pa[i][0][i-1]=='b'){
					l=i-1;
					r=pa[i][0].length()-i;
				}
				if(l>minl || r>minr){
					f=false;
				}
			}
			if(!f)continue;
			for(int i=1;i<=pa[i][1].length();i++)
			{
				int l,r;
				if(pa[i][1][i-1]=='b'){
					l=i-1;
					r=pa[i][1].length()-i;
				}
				if(l>minl || r>minr){
					f=false;
				}
			}
			if(f)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
