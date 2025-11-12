#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int num;
int a[500005];
int b[500005];
int c[500005];
int ac(int x,int y){
	int l=0,k=0;
	while(x!=0){
		l++;
		b[l]=x%2;
		x/=2;
	}
	while(y!=0){
		k++;
		c[k]=y%2;
		y/=2;
	}
	if(l>k){
		for(int i=k+1;i<=l;i++){
			c[i]=0;
		}
	}
	else if(l<k){
		for(int i=l+1;i<=k;i++){
			b[i]=0;
		}
	}
	int o=max(l,k);
	ll h=0;
	for(int i=1;i<=o;i++){
		if(b[i]!=c[i]){
			h+=pow(2,i-1);
		}
	}
	return h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=0;j<n;j++){		
		for(int i=1;i<=n;i++){
			if(j==0){
				if(a[i]==k){
					num++;
					a[i]=-1;
				}
			}
			else{
				ll l=a[i];
				if(l==-1)continue;
				for(int p=i+1;p<=i+j;p++){
					if(p>n) break;
					if(a[p]<0) break;
					l=ac(l,a[p]);
				}
				if(l==k){
					num++;
				for(int p=i+1;p<=i+j;p++){
					if(p>n) break;
					if(a[p]<0) break;
					a[p]=-1;			
					}	
				}
			}
		}
	}
	cout<<num;
	return 0;
}
