#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,l=1;
	for(int j=1;j<=m;j++){
		for(;j%2?i<=n:i>=1;j%2?i++:i--){
			if(a[l++]==x){
				printf("%d %d",j,i);
				return 0;
			}
		}
		if(j%2)i--;
		else i++;
	}
	return 0;
}