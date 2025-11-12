#include<bits/stdc++.h>
using namespace std;
int n,m,ai,x,y;
int a[110],a1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j];
		}
	}
	a1=a[1];
	int l=n*m;
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==a1){
			ai=i;
			break;
		}
	}
	if(ai%n==0){
		x=ai/n;
	}else{
		x=ai/n+1;
	}
	if(x%2==1){
		y=ai-(x-1)*n;
	}else{
		y=x*n-ai+1;
	}
	cout<<x<<" "<<y;
	return 0;
} 
