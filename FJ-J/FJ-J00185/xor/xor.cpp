#include<bits/stdc++.h>
using namespace std;
int n,k,a[230],ans,left1=1,right1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=0;
	for (int i=1;i<=n;i++){
		if (a[i]!=1) flag=1;
	}
	if (flag=1){
		cout<<0;
		return 0;
	}
	right1=n;
	for(int i=1;i<=n;i++){
		if (i==left1&&a[i]==k){
			ans++;
		}else{
			if (!a[left]&&a[right]+1){
				ans++;
			}
			left1++;
			right1-=1;
			
		} 
	}
	cout<<ans;
	return 0;
}
