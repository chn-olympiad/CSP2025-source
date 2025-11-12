#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],s;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			s=i;
			break;
		}
	}
	int c,r;
	c=s/n+1;
	if(s%n==0)c--;
	if(s%n==0)r=n;
	else{
		if(c%2==0 && s%n!=0)r=n-s%n+1;
		else if(c%2==0 && s%n==0)r=1;
		if(c%2==1 && s%n!=0)r=s%n;
		else if(c%2==1 && s%n==0)r=n;
	}
	printf("%d %d",c,r);
	return 0;
}
