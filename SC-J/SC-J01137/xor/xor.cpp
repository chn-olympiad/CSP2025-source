#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],len;
struct node{
	int l,r;	
}s[500050];
bool cmp(node x,node y){
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n-i+1;j++){
			int ans=a[j];
			for (int z=j+1;z<=i+j-1;z++) ans=ans^a[z];
			if(ans==k){
				s[++len].l=j;
				s[len].r=j+i-1;
			}
		}
	}
	sort(s+1,s+len+1,cmp);
	int end=s[1].r,cnt=1;
	for (int i=2;i<=len;i++){
		if(s[i].l>end){
			cnt++;
			end=s[i].r;
		}
	}
	cout<<cnt;
	return 0;
}