#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans=0;
string s1[N],s2[N],q1[N],q2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>q1[i]>>q2[i];
		for(int j=1;j<=n;j++)
			if(s1[j]==q1[i]&&s2[j]==q2[i])
				ans++;
		cout<<ans<<"\n";
	}
	
	return 0;
}
