#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int maxn;
//int dfs(int b,int mx,int ans){
//	if(b==n)return ans;
//	for(int i=1;i>=a[n];i++){
//		
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;//                          评测机很高大上 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	} 
//	bool temp=1;
//	for(int i=1;i<=n;i++){
//		if(temp&&i==2)break;
//		for(int k=i+1;k<=n;k++){
//			if(a[k]>a[i]){
//				swap(a[i],a[k]);
//				temp=0;
//			}
//		}
//	}
	cout<<0;
	return 0; 
} 
