#include<bits/stdc++.h> 
using namespace std;
long long n,k,p[500005],hi=0;
int ans[1000];
struct op{
	int left;
	int right;
}h[1000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int co=p[i];
			for(int e=i+1;e<=j;e++){
				co^=p[e];
			}
			if(co==k){
				hi++;
				h[hi].left=i;
				h[hi].right=j;
				
			}
		}
	}
	
	for(int u=1;u<=hi;u++){
		bool fg[500005]{0};
		for(int i=u;i<=hi;i++){
			for(int j=h[i].left;j<=h[i].right;j++){
				if(fg[j]==1){
					ans[u]--;
					break;
				}
				else fg[j]=1;
				
			}
			ans[u]++;
		}
	}
	int cot=0;
	for(int i=1;i<=1000;i++){
		cot=max(cot,ans[i]);
	}
	cout<<cot;
}