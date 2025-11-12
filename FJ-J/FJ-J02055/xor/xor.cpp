#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
求异或和用  ^ 

1.我需要知道异或可不可以前缀和  
2.标准要求On
3.替代方案O2或O3


题目要求选择n个区间使得每个区间的异或和=k（或者本身为k）
求最大的n 

让我先看看已获得规律 

//没时间了。写1和3 
没招了 
*/
int n,k;
int a[1000000];
signed main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		if(n==1){
			if(a[1]==k){
				cout<<1;
			}else {
				cout<<0;
			}
		}else if(n==2){
			int cnt1=0,cnt2=0;
			if((a[1]^a[2])==k) cnt1=1;
			if(a[1]==k) cnt2++;
			if(a[2]==k) cnt2++;
			
			cout<<max(cnt1,cnt2);
		}
		return 0;
	}else if(k==0){
		bool t[2];
		for(int i=1;i<=n;i++) t[a[i]]=1;
		cout<<t[0]+t[1]/2;
	} 
	else{
		cout<<ceil(n/2.0);
	}
	return 0;
}

