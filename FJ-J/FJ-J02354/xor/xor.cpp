#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
const int M=1e6+10;
struct node{
	int l,r,h;
}e[M];
int n,k,a[N],flag[N],t;
bool cmp(node b,node c){
	return b.h<c.h;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				t++;
				e[t].l=i;
				e[t].r=j;
				e[t].h=j-i+1;
			}
		}
	}
	if(t==1){
		cout<<1;
		return 0;
	}
	sort(e+1,e+t+1,cmp);
	int sum=0;
	for(int i=1;i<=t;i++){
		int fl=1;
		for(int j=e[i].l;j<=e[i].r;j++){
			if(flag[j]==1){
				fl=0;
				break;
			}
			flag[j]=1;
		}
		if(fl) sum++;
	}
	cout<<sum;
	return 0;
}
