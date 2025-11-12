#include<bits/stdc++.h>
using namespace std;
int n,m,num,t[101],a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i*n+j]);
			t[a[i*n+j]]++;
		}
	for(int i=100;i>=0;i--){
		for(int j=0;j<t[i];j++){
			num++;
			if(i==a[1]){
				printf("%d ",(num+n-1)/n);
				if(((num+n-1)/n)%2==1)printf("%d",(num+n-1)%n+1);
				else printf("%d",n-(num+n-1)%n);
			}
		}
	}
	return 0;
}
