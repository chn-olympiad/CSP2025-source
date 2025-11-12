#include<bits/stdc++.h>
using namespace std;
int n,m,s=1,L,H,a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) s++;
	}
	L=s/n;
	if(s%n!=0) L++;
	if(L%2==1)
	{
		H=s%n;
		if(H==0) H=n;
	} 
	else H=n-s%n+1;
	cout<<L<<" "<<H;
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
