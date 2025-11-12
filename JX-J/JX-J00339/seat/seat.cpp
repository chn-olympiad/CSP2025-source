#include<bits/stdc++.h>
using namespace std;
int t[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int f=m*n;
	for(int i=0;i<f;i++){
		scanf("%d",&t[i]);
	}
	int h=t[0];
	int p;
	sort(t,t+f);
	for(int i=f-1;i>=0;i--){
		if(t[i]==h){
			p=f-i;
			break;
		}
	}
	int a,b;
	a=p/m;
	b=p%m;
	if(a%2!=0&&b!=0){
		b=n-b+1;
	}
	if(b!=0){
		a+=1;
	}
	if(b==0){
		if(a%2==0){
			b=1;
		}else{
			b=n;
		}
	}
	printf("%d %d",a,b);
	return 0;
}
