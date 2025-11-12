//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<unordered_set>
using namespace std;
constexpr const int N=5e5,K=1<<20;
int n,k,a[N+1],pre[N+1];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int ans=0;
	unordered_set<int>cnt;
	cnt.insert(0);
	for(int r=1,l=1;r<=n;r++){
		if(cnt.count(k^pre[r])){
			ans++;
			l=r+1;
			cnt.clear();
		}
		cnt.insert(pre[r]);
		/*
		for(int i=l;i<=r;i++){
			if(pre[i-1]==(k^pre[r])){
				ans++;
				l=r+1;
				break;
			}
		}
		*/
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
