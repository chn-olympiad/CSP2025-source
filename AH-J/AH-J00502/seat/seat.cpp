#include<bits/stdc++.h>
using namespace std;
int n,m,t,h;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	h=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++)
				if(a[++t]==h){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
		}
		else{
			for(int j=n;j>=1;j--)
				if(a[++t]==h){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
		}
	}
	return 0;
}

/*
int h,t,x,y;
int a[110];
	for(int i=1;i<=n*m;i++)
		if(a[i]==h) t=i;
	x=(ceil)(1.0*t/n);
	if(x%2==1)
		if(t%n==0) y=n;
		else y=t%n;
	else
		if(t%n==0) y=1;
		else y=n-(t%n)+1;
	cout<<x<<' '<<y;
*/
