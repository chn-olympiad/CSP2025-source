#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[500010];
int n,k;
int checkA(){
	return n; 
} 
int cheakB(){
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			 if(a[i]==1){
				ans++;
			}
		}
		return ans;
	}else if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
		return ans;
	}
}
int checkC(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
		int num=a[i];
		for(int j=i+1;j<=n;j++){
			num^=a[j];
			if(num==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	return ans;
}
	
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<(0^3);
//	return 0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int flag=1;
	int flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			flag=0;
		}
		if(a[i]>1){
			flag2=0;
		}
	}
	if(k==0&&flag==1){
		cout<<checkA();
	}else if(k==1&&flag2==1){
		cout<<cheakB();
	}else{
		cout<<checkC();
	}
	return 0;
}
