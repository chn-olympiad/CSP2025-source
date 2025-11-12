#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,k,r,c;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) cin >>a[(i-1)*m+j];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=i;
			break;
		}
	}
	r=(k+n-1)/n;
	if(k%n) k%=n;
	else k=n;
	if(r%2) c=k;
	else c=n-k+1;
	cout <<r<<" "<<c;
	return 0;
}
