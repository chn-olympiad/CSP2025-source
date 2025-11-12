#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[5050];
long long max(long long x,long long y){
	return x>y? x:y;
}
struct node{
	int j;
	long long s;
	long long m;
};
queue<node> q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q.push({i,a[i],a[i]});
	}
	int c=0;
	
	while(!q.empty()){
		node t=q.front();
		q.pop();
		long long i=t.j+1;
		long long s=t.s;
		long long ma=t.m;
		if(s>ma*2){
			c++;
		}
		for(;i<=n;i++){
			q.push({i,s+a[i],max(ma,a[i])});
		}
	}
	cout<<c%998244353;
	return 0;
} 
