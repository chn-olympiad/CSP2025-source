#include<bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int now=a[1];
	sort(a+1,a+n*m+1);
	int pos;
	for(int i=1;i<=n*m;i++)
		if(a[i]==now){
			pos=n*m-i+1;
			break;
		}
	int nn,mm=pos/n+(pos%n>0);
	if(mm%2) nn=pos%n;
	else nn=(n-pos%n)%n+1;
	if(!nn) nn+=n;
	cout<<mm<<' '<<nn;
	fcloseall();
	return 0;
}
