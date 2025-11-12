#include<bits/stdc++.h>
using namespace std;

struct node{
	int l, r;
}b[1145];

bool cmp(node pre,node nxt){
	if(pre.l==nxt.l){
		return pre.r<pre.r;
	}else{
		return pre.l<pre.l;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	int n,k;
	int a[2000000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<n;i++){
		if(a[i]==k){
			b[++cnt].l=i;
			b[cnt].r=i;
		}
		for(int j=i;j<=n;j++){
			int tmp=a[i];
			for(int w=i+1;w<=j;w++){
				tmp=tmp^a[w];
			}
			if(tmp==k){
				b[++cnt].l=i;
//				cout<<i<<" ";
				b[cnt].r=j;
//				cout<<j<<"\n";
			}
			tmp=0;
		}
	}
//	sort(b+1,b+1+cnt,cmp);
//	cout<<cnt<<"\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<b[i].l<<" "<<b[i].r<<"\n";
//	}
	int ans=1,t=b[1].r;
	for(int i=2;i<=cnt;i++){
		if(b[i].l>t){
			ans++;
			t=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
