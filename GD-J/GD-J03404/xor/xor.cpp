#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
bool bb=1;
int c[500005],sum[500005];
struct node{
	int l,r;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<node>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1&&c[i]!=0) bb=0;
		sum[i]=sum[i-1]^c[i];
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				int u=sum[i]^sum[j-1];
				if(k==u){
					a.push_back({j,i});
				}
			}
		}
		if(a.empty()){
	
			cout<<0;
			return 0;
		}else{
			int b=a[0].r;
			cnt++;
			for(int i=1;i<a.size();i++){
				if(a[i].l>b){
					cnt++;
					b=a[i].r;
				}
			}
		}
		cout<<cnt;
	}else if(bb){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]){
				cnt++;
			}
		}
		if(k==1){
			cout<<cnt;
		}else{
			cnt=n-cnt;
			for(int i=2;i<=n;i++){
				if(c[i]&&c[i-1]){
					cnt++;
					i++;
				}
			}	
			cout<<cnt;
		}
	}
	
	return 0;
}
