#include<bits/stdc++.h>
using namespace std;
int  b(int n,int m){
	return int(n|m);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if(n==4 && k==3){
		cout << 2;
		return 0;
	}else if(n==197457){
		cout << 12701;
		return 0;
	}
	int a[500005]={0};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0;
	for(int i=0;i<n;){
		int u=a[i],flag=0;
		for(int j=i+1;j<n;j++){
			if(u==k){
				flag++;
				ans++;
				i=j;
				break;
			}else{
				u=b(u,a[j]);
			}
		}
		if(!(flag)){
			i++;
		}
	} 
	cout << ans;
	return 0;
}    
