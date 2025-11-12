#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
//	scanf("%d%d",&n,&m);
cin>>n>>m;
	int a[500];
	for(int i=1;i<=n*m;i++)
	//	scanf("%d",&a[i]);
	cin>>a[i];
	int xh=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xh){
		//	int v;
			if(i%n==0){
				c=i/n;
				if(c%2==1)r=n;
				else r=1;
			}//c=i/n,r=n;
			else{
			c=i/n+1;
			if(c%2==1)
			r=i%n;
			else
			r=n-i%n+1;
		}
		break;
	}
}
//	printf("%d %d",c,r);
cout<<c<<" "<<r;
	return 0;
} 
