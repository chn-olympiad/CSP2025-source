#include<iostream>
using namespace std;
const int N=5*1e5+10;
int a[N],n,m,l,r,mid,ans=-N,x;
int check(int k){
	int res=0;
	for(register int i=1;i<=n;i++){
		int cnt=1,num=a[i],ord=i;
		bool flag=0;
		for(;i<=n&&cnt<=k;i++,cnt++){
			if(num==m){
				std::cout<<i-cnt+1<<" "<<i<<'\n';
				res++,flag=1;
				break;
			}
			if(cnt==1);
			else num=num^a[i];
		}
		if(ord!=i)i--;
		if(!flag)i=ord;
	}
	return res;
}
signed main(int argc,char *argv[]){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m;
	for(register int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	int l=1,r=n;
	while(l<=r){
		mid=(r+l)/2;
		x=check(mid);
		if(x>ans){
			l=mid+1;
			ans=x;
		}else{
			r=mid-1;
		}
	}
	std::cout<<ans;
	return 0;
}
