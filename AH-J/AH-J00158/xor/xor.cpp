#include<bits/stdc++.h>
using namespace std;
int a[500000];
struct node{
	int l,r;
}b[2000000];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num,s=0,t=0,ans=0;
	cin>>n>>k;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			num=a[j]^a[i];
			if (num==k){
				b[s].l=i+1;
				b[s].r=j;
				s++;
				break;
			}
		}
	}
	sort(b,b+s,cmp);
	for(int i=0;i<s;i++){
		if (t<b[i].l){
			ans++;t=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
