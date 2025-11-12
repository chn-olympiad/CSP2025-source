#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int r,pos,x,y;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pos=i;
			break;
		}
	}
//	cout<<r<<" "<<pos<<endl;
	int x=(pos-1)/n+1,y=pos-(x-1)*n;
	if(x%2==0) y=n-y+1;
	printf("%d %d",x,y);
	return 0;
}

