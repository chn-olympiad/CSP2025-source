#include<bits/stdc++.h>
using namespace std;
struct lr{
	int l,r,len,d;
}res[500005];
int n,k,a[500005],sum[500005],vis[500005],ans,cnt;
lr maxn;
bool cmp(lr _A,lr _B){
	if(_A.d==_B.d){
		return _A.len<_B.len;
	}
	return _A.d<_B.d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	maxn.l=-1;
	maxn.r=-1;
	maxn.len=INT_MAX;
	maxn.d=INT_MAX;
	for(int i=1;i<=n+1;i++){
		res[i]=maxn;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp=sum[j]^sum[i-1];
			if(tmp==k){
				res[++cnt].l=i;
				res[cnt].r=j;
				res[cnt].len=j-i+1;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(((res[i].l>=res[j].l&&res[i].l<=res[j].r)||(res[i].r<=res[j].r&&res[i].r>=res[j].l))||((res[j].l>=res[i].l&&res[j].l<=res[i].r)||(res[j].r<=res[i].r&&res[j].r>=res[i].l))){
				res[i].d++;
				res[j].d++;
			}
		}
	}
	sort(res+1,res+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		bool flag=true;
		for(int j=1;j<i;j++){
			if(vis[j]==0){
				continue;
			}
			if(((res[i].l>=res[j].l&&res[i].l<=res[j].r)||(res[i].r<=res[j].r&&res[i].r>=res[j].l))||((res[j].l>=res[i].l&&res[j].l<=res[i].r)||(res[j].r<=res[i].r&&res[j].r>=res[i].l))){
				flag=false;
				break;
			}
		}
		if(flag){
			ans++;
			vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
}//rp++