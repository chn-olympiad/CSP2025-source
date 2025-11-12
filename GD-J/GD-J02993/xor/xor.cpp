#include<bits/stdc++.h>
using namespace std;
int a[500005],ma=-1;
int n,k;
void dps(int ans,int i1){
	for(int i =i1;i<=n;i++){
		int flag=a[i],j=i+1;
		while(flag==k){
			flag=int(flag^a[j++]);
			if(j>n||flag==k) break;
		}
		if(flag==k){
			ma=max(ma,ans+1);
			dps(ans+1,j+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	dps(0,1);
	cout << ma;
	return 0;
} 
