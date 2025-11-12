#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int c[100010];
node d[100010];
int cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n>10000){
		int ans=0;
		for(int i=1;i<=n;i++)
			if(c[i]==k)
				ans++;
		cout<<ans;
		return 0;
	}
	int len=0;
	if(n>=100){
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n-i+1;j++){
				if(j==1){
					sum=c[j];
					for(int a=j+1;a<=j+i-1;a++)
						sum^=c[a];
				}
				else{
					sum^=c[j-1];
					sum^=c[j+i-1];
				}
				if(sum==k){
					d[++len].l=j;
					d[len].r=j+i-1;
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				int sum=c[j];
				for(int a=j+1;a<=j+i-1;a++)
					sum^=c[a];
				if(sum==k){
					d[++len].l=j;
					d[len].r=j+i-1;
				}
			}
		}
	}
	sort(d+1,d+1+len,cmp);
	int x=d[1].r,sum=1;
	for(int i=2;i<=len;i++){
		if(d[i].l>x){
			x=d[i].r;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
