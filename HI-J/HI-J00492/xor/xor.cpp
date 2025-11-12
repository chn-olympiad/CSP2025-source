#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],h[500005];
int xora(int x,int y){
	int sum=0,z=1;
	while(x!=0||y!=0){
		int tot1=x%2,tot2=y%2;
		if(tot1!=tot2){
			sum+=z;
		}
		z*=2;
		x/=2,y/=2;
	}
	return sum;
}
int xorb(int l,int r){
	if(l==r){
		return a[l];
	}
	if(l==1){
		return h[r];
	}
	return xora(h[r],h[l-1]);
}
struct node{
	int l,r;
}q[1000005];
int top;
bool cmp(node a,node b){
	if(a.r==b.r){
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1){
			h[1]=a[i];
		}
		else{
			h[i]=xora(h[i-1],a[i]);
		}
	}
	if(n<=1003){
		for(int l=1;l<=n;++l){
			for(int r=l;r<=n;++r){
				if(xorb(l,r)==k){
					top++;
					q[top].l=l;
					q[top].r=r;
				}
			}
		}
		sort(q+1,q+top+1,cmp);
		int ans=0,ansr=0;
		for(int i=1;i<=top;++i){
			if(q[i].l>ansr){
				ans++;
				ansr=q[i].r;
			}
		}
		cout<<ans;
		return 0;	
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
