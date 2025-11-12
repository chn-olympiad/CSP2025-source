#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	} 
	int cnt = 0;
	for(int len = 1;len<=n;len++){
		for(int i = 1;i+len-1<=n;i++){
			int sum = 0,flag = 0;
			for(int j = i;j<=i+len-1;j++){
				if(vis[j]){
					flag = 1;
					break;
				}
				sum^=a[j]; 
			}
			if(flag)continue;
			if(sum == k){
				cnt++;
				for(int j = i;j<=i+len-1;j++){
					vis[j] = 1; 
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
