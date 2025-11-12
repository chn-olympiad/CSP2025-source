#include<bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 5e5+5;

int n,m,res,l=0x3fffffff,r;
int tree[N<<2],a[N];
bool vis[N];

std::vector<std::pair<int,int>> vec;

bool have(const int& i,const int& j);
void upd(const int& i,const int& j);
void build(const int& k,const int& l,const int& r);
int get(const int& k,const int& l,const int& r,const int& tl,const int& tr);

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
//	freopen("xor6.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	
	
	build(1,1,n);
	
	for(int k=1;k<=n;k++){
		for(int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			if(have(i,j))continue;
			if(get(1,1,n,i,j)==m){
				upd(i,j);
//				std::cout<<i<<" "<<j<<"\n";
				res++;
			}
		}
	}
	
	std::cout<<res;
	return 0;
}

bool have(const int& i,const int& j){
	if(vec.empty())return 0;
	for(auto k:vec){
		if((i<=k.second&&k.second<=j)||(i<=k.first&&k.first<=j)||(k.first<=i&&j<=k.second))
			return 1;
	}
	return 0;
}

void upd(const int& i,const int& j){
	vec.push_back({i,j});
}

void build(const int& k,const int& l,const int& r){
	if(l==r){
		tree[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*k,l,mid);
	build(2*k+1,mid+1,r);
	tree[k]=tree[2*k]^tree[2*k+1];
}

int get(const int& k,const int& l,const int& r,const int& tl,const int& tr){
//	std::cout<<l<<" "<<r<<" "<<tl<<" "<<tr<<"\n";
	if(tl>r||tr<l)
		return 0;
	if(tl<=l&&r<=tr)
		return tree[k];
	int mid=(l+r)>>1,sum=0;
	if(mid>=tl){
		int c=get(2*k,l,mid,tl,tr);
//		std::cout<<sum<<" "<<c<<" "<<(sum^c)<<"|";
		sum=sum^c;
	}
	if(mid<=tr){
		int c=get(2*k+1,mid+1,r,tl,tr);
//		std::cout<<sum<<" "<<c<<" "<<(sum^c)<<"|";
		sum=sum^c;
	}
//	std::cout<<"[]"<<sum<<"\n";
	return sum;
}