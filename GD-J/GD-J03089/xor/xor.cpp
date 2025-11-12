#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	bool isA=true;
	bool isB=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)isA=false;
		if(a[i]!=0&&a[i]!=1)isB=false;
	}
	if(k==0&&isA){
		cout<<n/2<<endl;
		return 0;
	}
	else if(k<=1&&isB){
		if(k==0){
			int cntf=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					ans+=cntf/2;		
					cntf=0;
				}
				else{
					cntf++;
				}
			}
			if(cntf!=0){
				ans+=cntf/2;
			}
			cout<<ans;
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
	}
	else {
		cout<<0;
	}
}
