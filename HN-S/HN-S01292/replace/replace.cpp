#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,base=1145;
string s1[200010],s2[200010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,m=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string s3,s4;
		int as=0;
		cin>>s3>>s4;
		for(int i=1;i<=n;i++){
			if(s3.size()<s1[i].size())
				break;
			for(int j=0;j<s3.size()-s1[i].size()+1;j++){
			int add=1;
				for(int k=0;k<s1[i].size();k++){
					if(s1[i][k]!=s3[j+k]||s2[i][k]!=s4[j+k]){
						add=0;
						break;
					}
				}
				as+=add;
			}
		}
		cout<<as<<'\n';
	}
	return 0;
}

