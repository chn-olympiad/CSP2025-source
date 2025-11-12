#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1e3;
int n,k,cnt,b;
struct data{
	int n;
	bool f;
} a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].n);
		if(a[i].n>1&&b!=1) b=1;
		if(a[i].n==k){
			cnt++;
			a[i].f=1; 
		}
	}
	if(k==0){
		int l=0;
		for(int i=1;i<=n;i++){
			if(a[i].f) l=0;
			if(a[i].n!=0&&l==0) l=a[i].n;
			else if(a[i].n!=0&&l==a[i].n){
				cnt++;
				l=0;
			}
		}
	}
	else if(b){
		for(int i=1;i<=n;i++){
			if(!a[i].f){
				int u[N]={0,a[i].n},u1=1;
				for(int j=i+1;j<=n;j++){
					int f1=0;
					if(a[j].f) break;
					for(int l=1;l<=u1;l++){
						u[l]=u[l]^a[j].n;
						if(u[l]==k){
							cnt++;
							i=j;
							f1=1;
							break;
						}
					}
					if(f1) break;
					u[++u1]=a[j].n;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
} 
