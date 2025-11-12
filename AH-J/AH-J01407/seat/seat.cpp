#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a,b,c,t[100005],h[1005][1005],j=0,k=0,xm;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	a=1;
	b=1;
	c=1;
	for(long long i=1;i<=n;i++){
		for(long long l=1;l<=m;l++){
			cin>>h[i][l];
			k++;
			t[k]=h[i][l];
		}
	}
	xm=t[1];
	sort(t+1,t+x+1,cmp);
	while(j!=x){
		j++;
		if(t[j]==xm){
			cout<<b<<" "<<a;
			return 0;
		}
		if(c==1){
			if(a==n){
				b++;
				c=2;
				continue;
			}
			if(t[j]!=xm){
				a++;
			}
		}else if(c==2){
			if(a==1){
				b++;
				c=1;
				continue;
			}
			if(t[j]!=xm){
				a--;
			}
		}
	}
	return 0;
}
