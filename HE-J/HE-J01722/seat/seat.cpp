#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];
int r,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],s;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
			break;
		}
	}
	if(s%n==0) r=s/n;
	else if(s%n!=0) r=s/n+1;
	if(s%n==0) c=n;
	else if(s%n!=0) c=s%n;
	if(r%2==0) c=n-c+1;
	cout<<r<<" "<<c;
	return 0;
}
