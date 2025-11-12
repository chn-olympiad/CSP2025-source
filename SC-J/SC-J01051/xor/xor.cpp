#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],sum[N],tot;
struct node{
	int s,e;
}lis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--){
			if((sum[j-1]^sum[i])==k){
				lis[++tot].s=j;
				lis[tot].e=i;
				break;
			}
		}
	int t=-1,ans=0;
	for(int i=1;i<=tot;i++)
		if(lis[i].s>t){
			ans++;
			t=lis[i].e;
		}
	cout<<ans;
	return 0;
}