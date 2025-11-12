#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s=n*m;
	for(int i=1;i<=s;i++){
		scanf("%d",&a[i]);
	}
	int z=a[1];
	sort(a+1,a+1+s);
	reverse(a+1,a+1+s);
	int t;
	for(int i=1;i<=s;i++){
		if(a[i]==z){
			t=i;
			break;
		}
	}
	if(t%n==0){
		printf("%d ",t/n);
		if((t/n)%2==0){
			printf("%d",1);
			return 0;
		}
		else{
			printf("%d",n);
			return 0;
		}
	}
	else{
		printf("%d ",t/n+1);
		if((t/n+1)%2==0){
			printf("%d",n-(t%n)+1);
			return 0;
		}
		else{
			printf("%d",t%n);
			return 0;
		}
	}
	return 0;
}
