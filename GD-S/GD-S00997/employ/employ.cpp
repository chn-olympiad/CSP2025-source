#include<bits/stdc++.h>
using namespace std;
int n,m,c[20],p[20],ans;
char s[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int fail=0,ac=0;
		for(int i=1;i<=n;i++){
			if(fail>=c[p[i]]){
				fail++;
				continue;
			}
			if(s[i]=='1') ac++;
			else fail++;
		}
		if(ac>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
}