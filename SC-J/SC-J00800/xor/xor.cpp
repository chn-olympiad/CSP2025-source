#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n,k;
long long a[N],head[N],cnt,ans[N];
struct node{
	long long l,r;
}b[N];
bool cmp(node x,node y){
	if(x.r==y.r)return x.l>y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		head[a[i]]=i;
		if((a[i]^a[i-1])==k)b[++cnt].l=i,b[cnt].r=i;
			else if(head[a[i]^k]!=0)b[++cnt].l=head[a[i]^k]+1,b[cnt].r=i;
	}
	sort(b+1,b+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++)cout<<b[i].l<<" "<<b[i].r<<endl;
	long long k=1;
	for(int i=1;i<=n;i++){
		while(b[k].r==i)ans[i]=max(ans[b[k].l-1]+1,ans[i]),k++;
		ans[i]=max(ans[i-1],ans[i]);
	//	cout<<ans[i]<<" ";
	}
	cout<<ans[n];
	return 0;
}