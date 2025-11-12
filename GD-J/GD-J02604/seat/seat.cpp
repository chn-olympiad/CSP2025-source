#include<bits/stdc++.h>
using namespace std;
int sco,a[110],pl=0;
int di(int x,int y){
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) sco=a[i];
	}
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i>=1;i--){
		if(a[i]==sco){
			pl=n*m+1-i;
		}
	}
	printf("%d ",di(pl,n));
	int l=di(pl,n),h=pl%n;
	if(h==0) h=n;
	if(l%2==1) printf("%d",h);
	else printf("%d",n-h+1);
	return 0;
} 
