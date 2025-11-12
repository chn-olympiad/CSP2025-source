#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct _{
	int l,r;
	bool operator<(const _ &c)const{
		if(l!=c.l)return l<c.l;
		return r<c.r;
	}
}b[N];
int a[N],n,k,bb,sum;
void dfs(int x,int ans){
	for(int i=x+1;i<bb;i++){
		if(b[x].r>=b[i].l)continue;
		dfs(i,ans+1);
	}
	sum=max(sum,ans); 
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=i;j<n;j++){
			ans^=a[j];
			if(ans==k){
				b[bb].l=i;
				b[bb].r=j;
				bb++;
			}
		}
	}
	sort(b,b+bb);
	for(int i=0;i<bb;i++){
		dfs(i,1);
	}
	cout<<sum;
}
