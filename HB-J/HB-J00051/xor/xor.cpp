#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,k,num,cnt,maxn,ans,s;
int a[N];
int x(int x,int y){
	ans=0,s=1;
	while(x!=0||y!=0){
		if(x%2!=y%2){
			ans+=s;
		}
		x/=2;
		y/=2;
		s*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int l=i;l<=n;l++){
			num=a[l];
			for(int r=l;r<=n;r++){
				if(r!=l){
					num=x(num,a[r]);
				}
				if(num==k){
					cnt++;
					l=r;
					break;
				}
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
