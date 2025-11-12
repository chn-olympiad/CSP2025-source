#include <bits/stdc++.h>
using namespace std;
int t,n,a[110000],b[110000],c[110000],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=(n/2);i++)ans+=a[i];
		cout <<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}