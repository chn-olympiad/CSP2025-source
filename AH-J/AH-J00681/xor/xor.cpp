#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,ans;
int xo(int l,int r){
	int w=a[l];
	for(int i=l+1;i<=r;i++)w=w^a[i];
	return w;
}
struct xl{
	int l,r;
}num[500005];
bool cmp(xl x,xl y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(xo(i,j)==k){
				num[++cnt]={i,j};
			}
		}
	sort(num+1,num+1+cnt,cmp);
	int r=num[1].r;
	for(int i=2;i<=cnt;i++){
		if(r<num[i].l){
			r=num[i].r;ans++;
		}
	}
	int ans2=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]==k)ans2++;
	}
	cout<<max(ans+1,ans2)<<endl;
	return 0;
}
