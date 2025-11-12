#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int p[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>p[i];
	int R=p[1];
	sort(p+1,p+n*m+1);
	for(int i=n*m;i>=1;--i) if(p[i]==R){ans=n*m-i+1;break;}
	int a=ans/n;
	int b=ans%n;
	if(a){
		if(a%2==0 && b==0) printf("%d %d",a,1);
		if(a%2==0 && b!=0) printf("%d %d",a+1,b);
		if(a%2==1 && b!=0) printf("%d %d",a+1,n-b+1);
		if(a%2==1 && b==0) printf("%d %d",a,n-b);
	}
	else printf("1 %d",b);
	return 0;
}
