#include<iostream>
#include<stdio.h>
#include<vector>
const int mod = 998244353;
using namespace std;

long long sum = 0;
void dfs(int node,int end,int k,int kk,vector<int>a,int nums){
	if(node == end){
		if(nums>=3 && k>kk)sum++;
		return;
	}
	dfs(node+1,end,k+a[node],kk,a,nums+1);
	dfs(node+1,end,k,kk,a,nums);
}

void bb_sort(vector<int>a,int size){
	int temp;
	for(int i = 0;i<size;i++){
		for(int j = i;j<size;j++){
			if(a[i]>a[j]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long x;
	long long y;
	bool tag = true;
	int n;
	cin>>n;
	vector<int>a(n,0);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		if(a[i]!=1){
			tag = false;
			break;
		}
	}
	if(tag){
	for(int i = 3;i<=n;i++){
		x = n;
		y = i;
		for(int j = 1;j<i;j++){
			x*=x-j;
			y*=y-j;
		}
		sum+=x/y;
	}
	cout<<sum%mod;
	}else{
		bb_sort(a,n);
		for(int i = 2;i<n;i++){
			dfs(0,i,0,a[i],a,1);
		}
		cout<<sum%mod;
	}
	//i am dying
	//pian fen cheng gong ,wo ai bao li.
}
