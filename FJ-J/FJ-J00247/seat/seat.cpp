#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,p,x=1,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i = 1;i<=n*m;i++) if(a[i]==tmp) p=i;
	while(p>m) x++,p-=m;
	if(x%2) y=p;
	else y=m-p+1;
	cout<<x<<' '<<y;
	return 0;
}
