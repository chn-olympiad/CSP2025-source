#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[5005];
vector<int> num;
vector<bool> path(5005);
int sum=0;
int n;

void dfs(int k,int t){
	if(k>=3){
		long long numsum=0;
		for(int i=0;i<k;i++){
			numsum+=num[i];
		}
		if(numsum>num[k-1]*2){
			sum++;
		}  
	}
	for(int i=t;i<n;i++){
		if(!path[i]){
		    path[i]=true;
		    num.push_back(a[i]);
		    dfs(k+1,i+1);
			num.pop_back();
		    path[i]=false;
		}	
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	dfs(0,0);
	cout<<(sum%998244353);
	return 0;
} 
