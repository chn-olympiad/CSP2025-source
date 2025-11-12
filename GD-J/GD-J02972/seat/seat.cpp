#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[205],s,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
			break;
		}
	}
	if(s%n==0)	x=s/n;
	else	x=s/n+1;
	if(x%2==1){
		if(s%n==0)	y=n;
		else	y=s%n;
	}
	else{
		if(s%n==0)	y=1;
		else	y=n-(s%n)+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
