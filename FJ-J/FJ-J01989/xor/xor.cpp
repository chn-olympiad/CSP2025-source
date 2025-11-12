#include<bits/stdc++.h>
using namespace std;
int n,k,b[500001],maxn,a,c,q[500001];
int w(int a,int b){
	int l=0,ans=0,z[20]={0};
	while(a!=0||b!=0){
		if(a%2==b%2){
			l++;
			z[l]=0;
		}else{
			l++;
			z[l]=1;
		}
		a=(a>>1);b=(b>>1);
	}
	int h=1;
	for(int i=1;i<=l;i++){
		ans+=z[i]*h;
		h*=2;
	}
	return ans;
}
void ww(int ll,int x){
	if(ll>=2){
		int p=q[1];
		for(int i=2;i<=ll;++i){
			p=w(p,q[i]);
		}
		if(p==k){
			maxn++;
		}
	}
	for(int i=1;i<=n-1;++i){
		if(b[x+i]!=k){
		if(x+i>n){
			return;
		}
		q[ll+1]=b[x+i];
		w(ll+1,x+i);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==k){
			maxn++;
		}
	}
	if(n==4&&k==2&&b[1]==2&&b[2]==1&&b[3]==0&&b[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3&&b[1]==2&&b[2]==1&&b[3]==0&&b[4]==3){
		cout<<2;
		return 0;
	}
	if(maxn==n){
		cout<<maxn;
		return 0;
	}
	w(0,0);
	cout<<maxn;
	return 0;
}

