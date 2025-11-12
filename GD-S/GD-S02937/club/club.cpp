#include<bits/stdc++.h>
using namespace std;
int n,a[5][100010],f[5][50010];
void work(){
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
	}
	sort(a[1]+1,a[1]+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--)
	ans+=a[1][i];
	cout<<ans<<'\n';
	return ;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
