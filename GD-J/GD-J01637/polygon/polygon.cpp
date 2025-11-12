#include<bits/stdc++.h>
using namespace std;

int t,n=5,a[5005]={0,1,2,3,4,5},maxn=INT_MIN,sum=0,ans=0,s=0,mx=INT_MIN;
int used[5005];

//int f(int k){
//	if(k==0 and mx*2<s){
//		ans++;
//	}else{
//		for(k=3;k<=n;k++){
//			for(int i=1;i<=n;i++){
//				if(used[a[i]]){
//					k--;
//					used[a[i]]--;
//					s+=a[i];
//					t=mx;
//					mx=max(mx,a[i]);
//					f(k);
//					k++;
//					used[a[i]]++;
//					s-=a[i];
//					mx=t;
//				}
//			}
//		}
//	}
//}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
//	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
//		used[a[i]]++;
	} 
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(maxn*2<sum) cout<<1;
		else cout<<0;
	}
//	f(3);
//	cout<<ans%998244353;
	
	return 0;
} 
