#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long k,a[500010],res;
struct node{
	int l,r;
	long long num;
}tree[500010];
struct node2{
	int l,r;
}ans[500010];
void build(int l,int r,int now){
	tree[now].l=l;
	tree[now].r=r;
	if (l==r){
		tree[now].num=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	tree[now].num=(tree[now*2].num^tree[now*2+1].num);
}
long long query(int x,int y,int now){
	if (x<=tree[now].l&&tree[now].r<=y){
		return tree[now].num;
	}
	long long t=-1;
	if (x<=tree[now*2].r){
		t=query(x,y,now*2);
	}
	if (t==-1&&tree[now*2+1].l<=y){
		t=query(x,y,now*2+1);
	}else if (tree[now*2+1].l<=y){
		t=(t^query(x,y,now*2+1));
	}
	return t;
}
bool cmp(node2 a,node2 b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if (n<=2){
		if (n==1&&a[1]==k){
			printf("1");
		}else if (n==1&&a[1]!=k){
			printf("0");
		}else if (n==2&&(a[1]^a[2])==k){
			printf("2");
		}else{
			printf("0");
		}
	}else{
		build(1,n,1);
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (query(i,j,1)==k){
					ans[++cnt].l=i;
					ans[cnt].r=j;
				}
			}
		}
		if (cnt==0){
			printf("0");
		}else{
			sort(ans+1,ans+1+cnt,cmp);
		    int now=ans[1].r;
		    res=1;
		    for (int i=2;i<=cnt;i++){
		    	if (ans[i].l>now){
		    		res++;
		    		now=ans[i].r;
				}
			}
			printf("%lld",res);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
