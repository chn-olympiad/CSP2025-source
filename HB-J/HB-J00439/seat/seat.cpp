#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,g,cnt;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;;i++)
		if(a[i]==g){
			cnt=i;
			break;
		}
	int c=(cnt-1)/n+1,r;
	if(c%2==1)r=(cnt-1)%n+1;
	else r=n+1-(cnt%n);
	cout<<c<<" "<<r;
	
	return 0;
}
