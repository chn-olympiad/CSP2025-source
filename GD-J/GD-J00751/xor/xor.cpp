#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN=5*(1e5)+10;
int d[MAXN],a[MAXN];
bool vis[MAXN];
//	cout<<(d[r]^d[l-1])<<" ";
bool check(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i])
		return false;
	}
	return true;
}
void mark(int l,int r){
	for(int i=l;i<=r;i++)
		vis[i]=true;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum^=a[i];
		d[i]=sum;
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((d[r]^d[l-1])==k&&check(l,r)){
				cnt++;
				mark(l,r);
			}
		}
	}
	cout<<cnt;
}
/*
4 2
2 1 0 3
*/ 
