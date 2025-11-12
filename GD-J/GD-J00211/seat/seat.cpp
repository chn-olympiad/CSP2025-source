#include<bits/stdc++.h>
using namespace std;
int n,m,f[105],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&f[i]);
	}s=f[1];
	sort(f+1,f+1+len,greater<int>());
	int p=lower_bound(f+1,f+1+len,s,greater<int>())-f;
	int l=(p-1)/n+1;
	int r=(p-1)%n+1;
	if(l%2==1)cout<<l<<" "<<r;
	else cout<<l<<" "<<n-r+1;
	return 0;
}
