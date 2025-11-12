#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int s=1,b;
int ansx,ansy;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) s++;
	}
	
	ansx=(s/(n*2))*2;
	s=(s-1)%(n*2)+1;
	
	if(s<=n) ansy=s,ansx++;
	else ansy=n+n-s+1,ansx+=2;
	
	cout<<ansx<<" "<<ansy<<"\n";
	
	return 0;
}
