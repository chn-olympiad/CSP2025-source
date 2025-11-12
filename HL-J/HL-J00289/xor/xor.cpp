#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int M = 50005;
int n;
long long k;
int nums[M];
bool vis[M];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}
	for(int i = 0;i<n;i++){
		if(nums[i]==k){
			cnt++;
			vis[i]=1;
		} 
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			bool flag = 1;
			for(int v = i;v<=j;v++){
				if(vis[v]==1) flag = 0;
			}
			if(!flag) continue;
			for(int v = i;v<j;v++){
				vis[v] = 1;
			}
			int xort = -1;
			for(int v = i;v<=j;v++){
				if(xort==-1) xort = nums[v];
				else xort = xort^ nums[v]; 
			}
			if(xort == k) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
