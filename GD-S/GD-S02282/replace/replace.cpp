#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[5000010];
string s1[5000010],q1[5000010],s2[5000010],q2[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(q1[i]==s1[j]&&q2[i]==s2[j]) ans[i]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
