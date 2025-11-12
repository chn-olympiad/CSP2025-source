#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int a[N],n,m;
int ans,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= n*m;++i)scanf("%d",&a[i]);
	d = a[1];
	sort(a+1,a+n*m+1);
	for(int i = 1;i <= n*m;++i){
		if(a[i]==d){
			ans = n*m-i+1;
			break; 
		}
	}
	int i = (ans+m-1)/m;
	int j = (i&1)?(ans-i*m+m):(i*m-ans+1);
	printf("%d %d",i,j);
	return 0;
}
