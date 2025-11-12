#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105],n,m,g,w;
bool cmp(int a,int b){
	return a>b;
}
int main(){//n=ÐÐ m=ÁÐ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==g)w=i;
	int lie=ceil(w*1.0/n);
	if(lie%2==1){
		int hang=w-(lie-1)*n;
		cout<<lie<<' '<<hang;
	}
	else{
		int hang=lie*n-w+1;
		cout<<lie<<' '<<hang;
	}
	return 0;
}
