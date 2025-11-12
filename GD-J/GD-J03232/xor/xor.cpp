#include<iostream>
using namespace std;
int n,k,a[500005],tp=0,t;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1&&tp<=1){
			if(a[i]==1) t++;
			else if(a[i]==0){
				tp=1;
			}
		}
		else tp=2;
	}
	if(tp==0){
		cout<<n/2;
		return 0;
	}
	if(tp==1){
		if(k==1){
			cout<<t;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i+1]==1){
					ans++;
					i++; 
				}
			}
			cout<<ans;
		}
		return 0;
	}
	return 0;
}
