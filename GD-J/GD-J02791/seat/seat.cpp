#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int k=n*m;
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	int num=a[1],id;
	stable_sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		if(a[i]==num){
			id=i;
		}
	}
	if(((id-1)/n)%2==0){
		printf("%d %d",(id-1)/n+1,(id-1)%n+1);
	}else printf("%d %d",(id-1)/n+1,n-((id-1)%n+1)+1);
	return 0;
}
