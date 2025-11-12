#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N+1];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("test.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	bool special_a=true;
	bool special_b=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			special_a=false;
		}
		if(a[i]>1){
			special_b=false;
		}
	}
	if(special_a){
		if(k==0){
			if(n<2){
				cout<<"0";
			}
			else{
				cout<<n/2;
			}
		}
	}
	if(special_b){
		if(k==1){
			int ans=0;
			int p=0;
			for(int i=2;i<=n;i++){
				if(((a[i]==1&&a[i-1]==0)||(a[i]==0&&a[i-1]==1))&&p<i-1){
					ans++;
					p=i;
				}
			}
			cout<<ans;
		}
		else if(k==0){
			int ans=0;
			int p=0;
			a[0]=0;
			for(int i=1;i<=n;i++){
				if(((a[i]==1&&a[i-1]==1&&p<i-1)||a[i]==0)){
					ans++;
					p=i;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}

