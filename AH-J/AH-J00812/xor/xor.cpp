#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
int sum[200005];
struct node{
	int l,r;
}b[200005];
bool cmp(node a,node b){
	return a.r<b.r;
}
int res;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int d1=sum[j];
			int d2=sum[i-1];
			int sum1=d1^d2; 
			if(sum1==k){
				b[++res]={i,j};
			}
		}
	}         
	sort(b+1,b+res+1,cmp);
	int pos=0;
	int cnt=0;
	for(int i=1;i<=res;i++){
		if(b[i].l>pos){
			cnt++;
			pos=b[i].r;
		}
	}
	cout<<cnt;
	return 0;
}
