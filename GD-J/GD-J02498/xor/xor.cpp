#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool zo[1000010];
int o[100000];
int p[100000];
int u[100000];
int yi(int x,int y){
	int cmp,z,w,h;
	for(int i=1;1;i++){
		o[i]=x%2;
		p[i]=y%2;
		x/=2;
		y/=2;
		if(x==0&&y==0){
			h=i;
			break;
		}
	}
	for(int i=1;i<=h;i++){
		if(o[i]!=p[i]){
			u[i]=1;
		}else if(o[i]!=p[i]){
			u[i]=0;
		}
		for(int j=1;j<=i;j++){
			w*=2;
		}
		z+=u[i]*w;
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,maxsum=0,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q=1;
			for(int l=i;l<=j;l++){
				if(zo[l]==1){
					break;
				}
					q=yi(a[l],q);
					if(a[l]==k){
					sum+=1;
					for(int f=i;f<=j;f++){
					zo[f]=1;
				}
			}	
			}
			if(q==k){
				sum+=1;
				
			}			
		}
	}
	cout<<sum;
	return 0;
} 
