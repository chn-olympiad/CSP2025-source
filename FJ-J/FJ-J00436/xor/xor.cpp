#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int son[2];
	int last = -1e7;
}tie[8000010];
int a[500010];
int pre[500010];
int sum[500010];
int n,k,tot;
void insert(int i){
	int idx = 0;
	int num = sum[i];
	bool b;
	int nxt;
	while(num || !idx){
		b = num%2;
		nxt = tie[idx].son[b];
		if(nxt == 0)tie[idx].son[b] = ++tot;
		idx = tie[idx].son[b];
		num/=2;
	}
	tie[idx].last = i;
	//cout<<idx<<" "<<i;
}
int find(int num){
	int idx = 0;
	bool b;
	int nxt;
	while(num || !idx){
		b = num%2;
		nxt = tie[idx].son[b];
		if(nxt == 0)return -1e7;
		idx = nxt;
		num/=2;
	}
	return tie[idx].last;
}//4 3 2 1 0 3
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	tie[0].son[0] = ++tot;
	tie[tot].last = 0;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1]^a[i];
		pre[i] = find(sum[i]^k)+1;
		insert(i);
	}
//	for(int i = 0;i<=tot;i++)cout<<tie[i].son[0]<<" "<<tie[i].son[1]<<"\n";
//	for(int i = 1;i<=n;i++)cout<<pre[i]<<" ";
	int ans = 0;
	int cur = 0;
	for(int i = 1;i<=n;i++){
		if(pre[i] > cur)ans++,cur = i;
	}
	cout<<ans; 
}
