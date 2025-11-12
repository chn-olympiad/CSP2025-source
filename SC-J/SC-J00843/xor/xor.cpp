#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
}c[2100000];
int a[N];
int b[2100][2100];
bool cmp(node A,node B){
	return A.r<B.r;
}
bool cmp1(node A,node B){
	return A.l>B.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int qweasdzxcqwe=0;
	bool qweasdzxc=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) qweasdzxc=0;
		if(a[i]==1) qweasdzxcqwe++;
	}
	if(qweasdzxc){
		if(k==1) cout<<qweasdzxcqwe;
		else cout<<n-qweasdzxcqwe;
		return 0;
	}
	int C=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i][j]=b[i][j-1]^a[j];
			if(b[i][j]==k){
				C++;
				c[C].l=i;
				c[C].r=j;
			}
		}
	}
	sort(c+1,c+1+C,cmp);
	if(C==1){
		cout<<"1";
		return 0;
	}else if(C==0){
		cout<<"0";
		return 0;
	}
	int shou=1,wei=1;
	for(int i=1;i<C;i++){
		if(c[i].r==c[i+1].r){
			wei=i+1;
		}else{
			sort(c+shou,c+1+wei,cmp1);
			shou=i+1;
			wei=i+1;
		}
	}
	sort(c+shou,c+1+wei,cmp1);
	shou=1;
	wei=1;
	int ans=0;
	for(int i=1;i<C;i++){
		if(c[i].r==c[i+1].r){
			wei=i+1;
		}else{
			wei=i+1;
			if(c[shou].r<c[wei].l){
				ans++;
				shou=i+1;
				wei++;
			}
		}
	}
	if(wei>=C){
		ans++;
	}
	cout<<ans;
	return 0;
}