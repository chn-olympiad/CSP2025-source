#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int n,m,ming,sea,ansx,ansy;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ming=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ming){
			sea=n*m-i+1;
			break;
		}
	}
	if(sea%n==0)ansx=sea/n;
	else ansx=sea/n+1;
	if(ansx%2==1)ansy=sea-(ansx-1)*n;
	else ansy=n-sea%n+1;
	cout<<ansx<<" "<<ansy;
	return 0;
}
