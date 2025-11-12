#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],e,o,maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)e++;
		if(a[i]==1)o++;
	}
	if(e==0){
		if(k==0){
			if(o%2){
				cout<<n-1;
				return 0;
			}else{
				cout<<n;
				return 0;
			}
		}
		if(k==1){
			if(o%2){
				cout<<n;
				return 0;
			}else{
				cout<<n-1;
				return 0;
			}
		} 
	}else{
		for(int i=0;i<n;i++){
			int ans=0,cnt=a[i];
			for(int j=i;j<n;j++){
				cnt^=a[j];
				ans++;
				if(ans>maxn&&cnt==k)maxn=ans;
			}
		}
		cout<<maxn-1;
	}
	return 0;
}
/*
卸腿儿！头、甲、抢、胸挂、背包。刘涛！！！花来！！！
当思念划过夜空
*/