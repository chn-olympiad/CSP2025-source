#include<bits/stdc++.h>
using namespace std;
struct man{
	int l,r,s;
}q[1048676];
int n,k;
int a[500500],t,s=1,ans;
bool v[500500],y;
bool cmp(man x,man y){
	if(x.s!=y.s)return x.s<y.s;
	return x.l<y.l;
}
int tt(int l,int r){
	int t=a[l];
	for(int i=l+1;i<=r;i++)t=t^a[i];
	return t;
}	
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);


	for(int i=1;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			if(tt(i,i+j)==k){
				q[s].l=i;
				q[s].r=i+j;
				q[s].s=j+1;
				s++;
			}
		}
	}
	sort(q+1,q+s,cmp);
	for(int i=1;i<s;i++){
		y=1;
		for(int j=q[i].l;j<=q[i].r;j++)if(v[j]){
			y=0;
			break;
		}
		if(y)ans++;
		for(int j=q[i].l;j<=q[i].r&&y;j++)v[j]=1;
	}
	printf("%d",ans);
	return 0;
}
