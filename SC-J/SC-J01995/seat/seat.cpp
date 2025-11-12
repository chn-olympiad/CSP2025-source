#include<bits/stdc++.h>
using namespace std;
int a[110110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s_R=a[1],b_R;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s_R==a[i]) b_R=i;
	}
	int x,y;
	x=b_R/n;
	if(b_R%n!=0) x++;
	cout<<x<<' ';
	if(x%2){
		if(b_R%x) cout<<b_R%x;
		else cout<<n;
	} 
	else {
		if(b_R%x) cout<<(n-(b_R%x)+1);
		else cout<<1;
	}
	return 0;
}