#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
struct node{
	long long l,r;
}m[N];
long long n,k;
bool mp[N];
bool cmp(node x,node y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r>y.r;
}
bool check(long long l,long long r){
	long long ct=0;
	for(int i=l;i<=r;i++){
		ct=ct^a[i];
	}
	return ct==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long ct=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(check(i,j)){
				ct++;
				m[ct].l=i;
				m[ct].r=j;
			}
		}
	}
	long long num=0;
	sort(m+1,m+ct+1,cmp);
	for(long long i=1;i<=ct;i++){
		if(!mp[i]){
			for(long long j=i+1;j<=ct;j++){
				if(!mp[j]&&(m[i].l<=m[j].l&&m[i].r>=m[j].r)){
					mp[j]=1;
					num++;
				}
			}
		}
	}
	cout<<ct-num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
