#include<bits/stdc++.h>
using namespace std;
long long N,K;
long long a[500005];
long long b[500005];
struct node{
	int left;
	int right;
};
bool cmp(node a,node b){
	return a.right<b.right;
}
node c[500005];
void solve1(){
	cout<<N/2;
	return ;
}
void solve2(){
	int ans=0;
	if(K==1){
		for(int i=1;i<=N;i++){
			if(a[i]==1)ans++;
		}
	}else{
		for(int i=1;i<=N;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
	return ;
}
void solve3(){
	int ans=0;
	b[0]=0;
	for(int i=1;i<=N;i++){
		b[i]=b[i-1]^a[i];
	}
	int p=0;
	for(int l=1;l<=N;l++){
		for(int r=l;r<=N;r++){
//			cout<<(b[r]^b[l-1])<<' ';
			if((b[r]^b[l-1])==K){
//				cout<<l<<'~'<<r<<endl;
				c[++p].left=l;
				c[++p].right=r;
				break;
			}
		}
	}
	sort(c+1,c+p+1,cmp);
	int s=0;
	for(int i=1;i<=p;i++){
		if(c[i].left>s){
			ans++;
			s=c[i].right;
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N>>K;
	bool f1=1,f2=1;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=0;
			if(a[i]!=0)f2=0;
		}
	}
	if(f1)solve1();
	else if(f2)solve2();
	else solve3();
	return 0;
}
//I love CCF very much