#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int a[500005],ans=-1;
int n,k;
int dp[500005];
int dfs(int l){
	int t=0;
	int s=0;
	if(l==n)return 0;
	for(int i=l;;i++){
		t^=a[i];
		if(t==k){
			s++;
			s+=dfs(i+1);
			return s;
			}
		}
	}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0);
    return 0;
   
}
