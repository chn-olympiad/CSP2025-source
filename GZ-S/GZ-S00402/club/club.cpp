//GZ-S00402 袁彬航 贵阳市第一中学
#include <bits/stdc++.h>
using namespace std;
int b[5];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k,n;
	cin>>k;
	while(k--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>b[1]>>b[2]>>b[3];
			sort(b+1,b+1+3,cmp);
			ans+=b[1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
