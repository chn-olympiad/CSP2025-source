#include<bits/stdc++.h>
using namespace std;
long long a1,a[1050],b,c,n,m,sum,ans,p;
bool cmp(int x,int y){
	return(x>y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			p=i;break;
		}
	}
	int l=p/n;
	if(p%n!=0)l++;
	int h=p%n;
	if(h==0)h=n;
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<' '<<h;
	return 0;
}

