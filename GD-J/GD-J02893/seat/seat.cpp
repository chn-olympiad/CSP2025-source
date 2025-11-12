#include<bits/stdc++.h>
using namespace std;
int n,m;
int self,sum=0;
int a[500+50],ansx,ansy;
void anser(int anss){
	int mod=anss%n;
	if(mod==0){
		ansx=anss/n;
		if(ansx%2==0)ansy=1;
		else ansy=n;
	}
	else{
		ansx=(anss/n)+1;
		if(ansx%2==1){
			ansy=mod;
		}else{
			ansy=n+1-mod;
		}
	}
	
	
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	self=a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>self)sum++;
	}
	sum++;
	anser(sum);
	//cout<<sum;
	printf("%d %d",ansx,ansy);
	return 0;
}

