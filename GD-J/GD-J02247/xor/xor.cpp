#include<iostream>
using namespace std;
long long n,k;
long long ans=0;
long long a[500004];
bool tree[500004*4];
bool lazy[500004*4];
void push_down(int id,int l,int r){
	if(lazy[id]==1){
		tree[id]=1;
		if(l!=r){
			lazy[id*2]=1;
			lazy[id*2+1]=1;
		}
		
	}
}
void add(int id,int l,int r,int x,int y){
	push_down(id,l,r);
	if(x<=l&&r<=y){
		tree[id]=1;
		if(l!=r){
			lazy[id*2]=1;
			lazy[id*2+1]=1;
		}
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid)add(id*2,l,mid,x,y);
	if(mid+1<=y)add(id*2+1,mid+1,r,x,y);
	tree[id]=tree[id*2]|tree[id*2+1];
}
bool ask(int id,int l,int r,int x,int y){
	push_down(id,l,r);
	if(x<=l&&r<=y){
		return tree[id];
	}
	int mid=(l+r)/2;
	bool ans=0;
	if(x<=mid)ans=ans|ask(id*2,l,mid,x,y);
	if(mid+1<=y)ans=ans|ask(id*2+1,mid+1,r,x,y);
	return ans;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int r=i+len-1;
			if(ask(1,1,n,i,r)){
				continue;
			}
			long long num=0;
			for(int j=i;j<=r;j++){
				num^=a[j];
			}
			if(num==k){
				add(1,1,n,i,r);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
