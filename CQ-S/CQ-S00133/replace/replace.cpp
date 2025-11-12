#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[10110],b[10101];
string s,s1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	for(int i=1; i<=q; i++) {
		cin>>s>>s1;
		long long maxx=0,minn=s.size(),ans=0;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]!=s1[j])
			{
				maxx=s[j];
				if(minn==s.size())
				minn=j;
			}
		 } 
		for(int l=0; l<s1.size(); l++) {
			string temp="",temp1="";
			for(int r=l; r<=minn; r++) {
				temp+=s[r];
				temp1+=s1[r];
				for(int o=maxx; o<=maxx; o++) {
					if(a[o]==temp&&b[o]==temp1)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
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
