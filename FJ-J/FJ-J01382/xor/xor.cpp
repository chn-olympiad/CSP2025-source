#include<bits/stdc++.h>
using namespace std;
int n,k,tmp=0;
long long ans=1;
const int N=5*100000+5;
int a[N],s[N];
struct node{
	int la;
	int ra;
}b[1000005];
bool cmp(node x,node y){
	if(x.ra<y.ra)return 1;
	else return 0;
}
void dfs(int l,int r){
	if(r==l){
		return ;
	}
	if((s[r]^s[l-1])==k){
		++tmp;
		b[tmp].la=l;
		b[tmp].ra=r;
	}
	for(int i=l;i<r;i++){
		dfs(l,i);
		dfs(i+1,r);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		if(a[i]==k){
			++tmp;
			b[tmp].la=i;
			b[tmp].ra=i;
		}
	}
	dfs(1,n);
	sort(b+1,b+tmp+1,cmp);
	if(tmp==0){
		cout<<0;
		return 0;
	}
	if(tmp==1){
		cout<<1;
		return 0;
	}
	int rb=b[1].ra;
	for(int i=2;i<=tmp;i++){
		if(b[i].la>rb){
			ans++;
			rb=b[i].ra;
		}
	}
	cout<<ans;
	return 0;
}
