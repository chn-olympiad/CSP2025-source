#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s; cin>>s;
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
	}
	for(int i=0;i<s.size();i++) {
		if(s[i]=='1')
			ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
