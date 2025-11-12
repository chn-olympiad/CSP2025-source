#include<bits/stdc++.h>
using namespace std;
int n,t,c,a[5010],b[5010];
void l(int x,int y,int z,int p,int q){
	if(z==q){
		if(x>p*2){
			t=(t+1)%998244353;
		}
		return;
	}
	if(y==n+1){
		return;
	}
	int rr=max(p,a[y]);
	l(x+a[y],y+1,z+1,rr,q);
	l(x,y+1,z,p,q);
}
int ll(int x,int y){
	int q=1,ee=x;
	while(x>0){
		q=q*y;
		for(int i=ee;i>=2;i--){
			if(q%i==0 && b[i]==0){
				b[i]=1;
				q/=i;
			}
		}
		q=q%998244353;
		y--;
		x--;
	}
	return q;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			c++;
		}
	}
	if(c==0){
		for(int i=3;i<=n;i++){
			memset(b,0,sizeof(b));
			t=(t+ll(i,n))%998244353;
		}
	}
	else{
		for(int i=3;i<=n;i++){
			l(0,1,0,0,i);
		}
	}
	cout<<t;
	return 0;
}
