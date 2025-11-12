#include <bits/stdc++.h>
using namespace std;
const int N=1e2; 
int n,m,s,a[N+10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1,k=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++,k++)
				if(a[k]==s) printf("%d %d",i,j);
		}else{
			for(int j=n;j>=1;j--,k++)
				if(a[k]==s) printf("%d %d",i,j);
		}
	}
}
