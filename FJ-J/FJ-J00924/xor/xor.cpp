#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],num=0,vis[500005]={},ans;
int ch(int x,int y){
	int sum=a[x];
	for(int i=x+1;i<=y;i++){
		sum^=a[i];
	}
	if(sum==k)return 1;
	else return 0;
}
int c(int x,int y){
	bool p=1;
	for(int i=x;i<=y;i++){
		if(vis[i]!=0){
			p=0;
			break;
		}
	}
	return p;
}
struct s{
	int l;
	int r;
}q[500005];
bool cmp(s x,s y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ch(i,j)){
				num++;
				q[num].l=i;
				q[num].r=j;
				
			}
		}
	}
	sort(q+1,q+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(c(q[i].l,q[i].r)){
			for(int j=q[i].l;j<=q[i].r;j++){
				vis[j]=1;
			}
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

