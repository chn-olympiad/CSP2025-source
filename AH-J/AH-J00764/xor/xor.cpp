#include<bits/stdc++.h>
using namespace std;
struct node{
	int st,ed;
}l[500010];
int n,k,a[500010],len;
long long sum[500010];
bool cmp(node a,node b){
	return a.ed<b.ed;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==1){
				if(sum[j]==k){
					l[++len]={i,j};
					break;
				}
			}else{
				long long tmp=sum[j]^sum[i-1];
				if(tmp==k){ 
					l[++len]={i,j};
					break;
				}
			}
		}
	}
	sort(l+1,l+1+len,cmp);
	long long ans=0;
	int r=0;
	for(int i=1;i<=len;i++){
		if(l[i].st>r){
			ans++;
			r=l[i].ed;
		}
	}
	cout<<ans;
	return 0;
}
