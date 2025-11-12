#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N],b[N*N],n,m,k,z,s,ss;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>b[i];
	k=b[1];
	sort(b+1,b+1+n*m);
	reverse(b+1,b+1+n*m);
	for (int i=1;i<=n*m;i++) if (b[i]==k){
		z=i;
		break;
	}s=z/n;
	ss=z%n;
	if (ss==0){
		ss=m;
	}if (ss!=m) s++;
	if (s%2==0) ss=m+1-ss;
	cout<<s<<' '<<ss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
