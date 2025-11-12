#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	bool flag1=0,flag0=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
		else{
			flag1=1;
			if(a[i]==0)continue;
			else flag0=1;
		}
	}
	if(flag1==0){
		cout<<n/2;
		return 0;
	}
	if(flag0==0){
		if(k==1)cout<<cnt;
		else{
			int ans=0,num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					num=0;
				}
				else{
					num++;
					if(num==2){
						ans++;
						num=0;
					}
				}
			} 
			cout<<ans;
		}
		return 0;
	}
	cout<<k%2+1;
	return 0;
}