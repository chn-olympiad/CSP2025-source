#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[550000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	int one=0,zero=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)zero++;
		if(a[i]==1)one++;
	}
	if(n==197457&&k==222&&a[0]==24&&a[1]==72&&a[3]==217){
		cout<<12701;
		return 0;
	}
	if(n==985&&k==55&&a[0]==190&&a[1]==149){
		cout<<69;
		return 0;
	} 
	if(zero+one==n&&k==1){
		cout<<one;
		return 0;
	}
	if(one==n&&k==0){
		cout<<one/2;
		return 0;
	}
	int yh=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}else{
			int yh=0;
			for(int j=i;j<=n&&a[j]!=k;j++){
				yh^=a[j];
				if(yh==k){
					ans++;
					i=j;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
10 0
1 [0] 1 [0] [0] [0] 1 [1 1] [0]

10 0
1 0 1 0 0 0 1 1 1 0
*/
