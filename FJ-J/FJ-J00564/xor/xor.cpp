#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int K=1e3+5;
int a[N],n,k;
int q[N];
int cnt=0;
int ans=0;
struct node{
	int l,r;
}t[N];

int p(int l,int r){
	return q[r]^q[l-1];
}

bool cmp(node a,node b){
	return a.r<b.r;
}

int AandB(){
	int ct=0;
	int l=1;
	for(int r=1;r<=n;++r){
		int t=q[r]^q[l-1];
		if(t==k){
			++ct;
			l=r+1;
		}
	}
	return ct;
}


int main(){

	//1048576;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i],q[i]=q[i-1]^a[i];
	if(n>3000){
		cout<<AandB();
		return 0; 
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(p(i,j)==k){
				t[++cnt].l=i;
				t[cnt].r=j;
				//cout<<j<<"\n"; 
				break;
			}
		}
	}
	//sort 
	sort(t+1,t+cnt+1,cmp);
	int R=0;
	for(int i=1;i<=cnt;++i){
		//cout<<t[i].l<<" "<<t[i].r<<"\n";
		if(t[i].l>R){
			++ans;
			R=t[i].r;
		}
	}
	cout<<ans;
	
	return 0;
} 
/*

4 0
2 1 0 3

*/
