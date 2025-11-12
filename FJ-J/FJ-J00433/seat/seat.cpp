#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			pos=i;
			break;
		}
	}
	int k=0;
	if(int(ceil(pos*1.0/n))%2!=0) k=pos%n;
	else k=(m-pos%n+1)%n;
	if(k==0) k=n;
	printf("%d %d",int(ceil(pos*1.0/n)),k);
	return 0;
}

