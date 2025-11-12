#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],ax;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	ax=a[1];
	int ansx=1,ansy=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(ansx&1){
			ansy++;
			if(ansy>n) ansy=n,ansx++;
		}
		else{
			ansy--;
			if(ansy<1) ansy=1,ansx++;
		}
		if(ax==a[i]) break;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
