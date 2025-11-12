#include<bits/stdc++.h>
using namespace std;
int a[100000],n,m,s,b[100000],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&s);
			a[cnt]=s;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]<=a[j]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
		}
	}
	if(a[b[1]]/n%2==1)printf("%d %d",n-a[b[1]]%n+1,a[b[1]]/n+1);
	else printf("%d %d",a[b[1]]%n+1,a[b[1]]/n+1);
	return 0;
}
