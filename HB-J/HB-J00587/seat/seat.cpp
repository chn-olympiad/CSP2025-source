#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],x,y;
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	y=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++) if(a[i]==y){x=i;break;}
	cout<<x/n+1<<" ";
	if((x/n+1)%2==1) cout<<(x%n)+1;
	else cout<<n-(x%n);
	return 0;
}
