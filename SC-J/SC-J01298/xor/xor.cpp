#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],cnt,ans;
struct node{
	int l,r;
}t[20000000];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=30000){
		for(int i=1;i<=n;i++){
			int sum=a[i];
			if(sum==k){
				t[++cnt].l=i;
				t[cnt].r=i;
			}
			for(int j=i+1;j<=n;j++){
				sum^=a[j];
				if(sum==k){
					t[++cnt].l=i;
					t[cnt].r=j;
				}
			}
		}
		sort(t+1,t+cnt+1,cmp);
		int k=0;
		for(int i=1;i<=cnt;i++){
			if(t[i].l>k){
				k=t[i].r;
				ans++;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}