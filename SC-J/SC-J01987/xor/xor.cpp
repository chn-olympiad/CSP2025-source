#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,a[N],k,cnt,ct;
vector<int>f[N];
struct node{
	int l,r;
}st[N];
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int p(int a,int b){
	
	int t[N]={};
	int w=0;
	while(a>0||b>0){
		w++;
		if(a%2!=b%2){
			t[w]=1;
		}
		a/=2;b/=2;
	}
	int num=0;
	for(int i=1;i<=w;i++){
		num+=t[i]*pow(2,i-1);
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(j==0){
				f[i].push_back(a[i]);
			}else{
				f[i].push_back(p(f[i][j-1],a[i+j]));
			}		
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(f[i][j]==k){
				cnt++;
				st[cnt].l=i;
				st[cnt].r=i+j;
			}
		}
	}
	sort(st,st+cnt+1,cmp);
	int no=0;
	for(int i=1;i<=cnt;i++){
		if(no<st[i].l){
			no=st[i].r;
			ct++;
		}
	}
	cout<<ct;
	return 0;
}