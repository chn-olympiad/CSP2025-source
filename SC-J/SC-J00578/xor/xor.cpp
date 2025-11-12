#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500020],s[500020];
int n,k,ans1,ans2;
//void dfs(int b,int e,int num){
////	if(b>=n){
////		ans=max(ans,num);
////		num=0;
////		return;
////	}
//	if((s[e]^s[b-1])==k){
//		num++;
//		b=e+1;
//		e++;
//	}
//	for(int i=b;i<=n;i++){
//		for(int j=b+1;j<=n;j++){
//			dfs(i,j,num);
//		}
//		ans=max(ans,num);
//		num=0;
//	}
//} 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);

	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				i=j+1;
				j++;
				ans1++;
			}			
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1])==k){
				i=j-1;
				j--;
				ans2++;
			}			
		}
	}
	cout<<max(ans1,ans2);
//	int ans1=0;
//	for(int t=1;t<=n;t++){
//		int e=t,b=t;
//		ans=0;
//		for(int i=b;i<=n;i++){
//			for(int j=e;j<=n;j++){
//				if((s[j]^s[i-1])==k){
//					ans++;
//					i=j+1;
//					j++;
//				}
//			}
//		}
//		ans1=max(ans1,ans);
//	} 
//	dfs(1,1,0);
	return 0;
} 
/*
4 2
2 1 0 3
*/
