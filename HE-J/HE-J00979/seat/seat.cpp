#include <bits/stdc++.h>
using namespace std;
int m,n;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x=n*m-1;
	int a[x];
	int c=0;
	for(int i=0;i<=x;i++){
		scanf("%d",&a[i]);
	}
	for(int j=0;j<=x;j++){
		if(a[0]<a[j+1]){
			c = c+1;
		}
	}
	if(n%2!=0&&m%2!=0)c=c+1;
	if(c==1){
		printf("1 1");
	}
	else{
		if(c<=n){
			printf("1 ","%d",c);
		}
		if(c==n*m){
			if(m%2==0){
				cout<<m<<" 1";
			}
			else{
				cout<<m<<" "<<n;
			}
		}
		else{

			int s=1+c/n;
			int o=c%n;

			if(s%2==0){
				cout<<s<<" "<<n-o+1;
			}
			else{
				cout<<s<<" "<<o;
			}
		}
	}
	return 0;
}
