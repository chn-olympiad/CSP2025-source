#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3][100010],ans=0,n,T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;memset(a,0,sizeof(a));ans = 0;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[j][i];
		sort(a[0]+1,a[0]+n+1);
		for(int i=n/2+1;i<=n;i++)ans+=a[0][i];
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
