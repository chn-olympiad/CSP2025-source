#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e8+5;
int n,k;
int a[N],b[N];
bool bol[N];
struct node{
	int l,r,len;
}g[M];
bool cmp(node x,node y){
	if(x.len==y.len) return x.l<y.l;
	return x.len<y.len;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1) b[i]=b[i-1] xor a[i];
		else b[1]=a[1];
	}
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(((b[i] xor b[j-1])==k)&&(j>1)||(b[i]==k)&&(j==1)){
				cnt++;
				g[cnt].l=j,g[cnt].r=i,g[cnt].len=i-j;
			}
		}
	}
	sort(g+1,g+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++){
//		cout<<g[i].l<<" "<<g[i].r<<" "<<g[i].len<<endl;
//	}
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		bool flag=1;
		for(int j=g[i].l;j<=g[i].l+g[i].len;j++){
			if(bol[j]==1){
				flag=0;
				break;
			}
		}
		if(flag==1){
			ans++;
			for(int j=g[i].l;j<=g[i].l+g[i].len;j++){
				bol[j]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<bol[i]<<" ";
	cout<<ans;
	return 0;
}
/*
rule: if a xor b=c then b=c xor a
*/
