#include<bits/stdc++.h> 
using namespace std;
int a[5010];
int maxn=-100000,num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		num+=a[i];
	}
//	int b=3;
//	while(b!=n+1){
//		
//	}
	if(maxn*2>=n) cout<<0;
	if(maxn*2<n) cout<<1;
	return 0;
}
//ÎÒÐ´¸öÆ¨

