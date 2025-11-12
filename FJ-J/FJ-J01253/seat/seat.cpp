#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==mark){
			k=i; break;
		}
	if(k%n==0){
		y=k/n;
		if(y%2==1) x=n;
		else x=1;
	}
	else{
		y=k/n+1;
		if(y%2==1) x=k%n;
		else x=n-k%n+1;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}