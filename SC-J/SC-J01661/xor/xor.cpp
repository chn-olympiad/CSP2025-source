#include<bits/stdc++.h>
using namespace std;
//通过计算弄出所有等于k的值后贪心
int n,k;
int a[500005];
int b[500005];
struct node{
	int val;
	int id;
};
node su[500005];
node sum[500005];
bool cmp(node x,node y){
	if(x.val!=y.val)return x.val<y.val;
	else return x.id<y.id;
}
struct Node {
	int x,y;
};
Node arr[500005];
bool ck(Node x,Node y){
	if(x.y!=y.y)return x.y<y.y;
	else return x.x>y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su[i].val=su[i-1].val^a[i];
		su[i].id=i;
	}
	int cnt=0;
	sort(su+1,su+n+1,cmp);
	int cntt=1;
	sum[1].val=su[1].val;
	sum[1].id=su[1].id;
	b[1]=1;
	for(int i=1;i<=n;i++){
		if(su[i].val!=su[i-1].val){
			cntt++;
			b[cntt]=i;
			sum[cntt].val=su[i].val;
			sum[cntt].id=su[i].id;
		}
	}
//	for(int i=1;i<=cntt;i++){
//		cout<<sum[i].val<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=cntt;i++){
//		cout<<sum[i].id<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=cntt;i++){
		int ca=k^sum[i-1].val;
		int l=0,r=cntt;
		int ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[mid].val<=ca){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		cnt++;
		if(sum[ans].val!=ca||sum[ans].id<sum[i].id){
			continue;
		}
		arr[cnt]={sum[i].id,sum[ans].id};
//		cout<<sum[i].id<<" "<<sum[ans].id<<endl;
	}
	sort(arr+1,arr+cnt+1,ck);
	int reale=0;
	int cnt1=0;
	for(int i=1;i<=cnt;i++){
		if(reale<arr[i].x){
			cnt1++;
			reale=arr[i].y;
		}
	}
	cout<<cnt1;
	return 0;
}