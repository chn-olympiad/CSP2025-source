#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
array<string,N> s1,s2;
array<int,N> len;
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int l=t1.size();
		for(int i=0;i<l;i++){
			for(int j=0;j<n;j++){
				if(i+len[j]-1<l){
					if(t1.substr(i,len[j])==s1[j]&&t2.substr(i,len[j])==s2[j]){
						if(t1.substr(0,i)==t2.substr(0,i)&&t1.substr(i+len[j])==t2.substr(i+len[j])){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
