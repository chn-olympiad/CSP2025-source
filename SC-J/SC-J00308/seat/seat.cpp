#include<bits/stdc++.h>
using namespace std;
int a[105];
bool compare(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,sp;
	cin>>n>>m;
	t=n*m;
	cin>>a[1];
	sp=a[1];
	for(int i=2;i<=t;i++)
		cin>>a[i];
	sort(a+1,a+t+1,compare);
	int k;
	for(int i=1;i<=t;i++)
		if(a[i]==sp){
			k=i;
			break;
		}
	int x,y;
	x=ceil(double(k)/n);
	if(x%2==1){
		y=k%m;
		if(y==0)
			y=m;	
	}
	else
		y=n-k%m;
	cout<<x<<" "<<y;
	return 0;
} 