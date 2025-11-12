#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[1100];
long long b,c,x,ss=1;
bool cmp(int x,int y){
		return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long i;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		x=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==x){
			break;
		}
		ss++;
	}
	b=ss/n;
	c=ss%n;
	if(c==0 && b%2==1){
			cout<<b<<" "<<n;
			return 0;
	}
	if(c==0 && b%2==0){
			cout<<b<<" "<<1;
			return 0;
	}
	if((b+1)%2==0){
			cout<<b+1<<" "<<(n-c+1);
			return 0;
	}
	if ((b+1)%2==1){
			cout<<b+1<<" "<<c;
	}
	return 0;
}
