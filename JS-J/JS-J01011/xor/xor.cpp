#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t,ans,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=a[i];
		if(t==k){
			cnt++;
			t=a[i+1];
			for(int j=i+2;j<=n;j++){
				t=t^a[j];
				if(t==k){
					cnt++;
					t=a[j+1];
					j++;
				}
			}
		}
		else{
			for(int j=i+1;j<=n;j++){
				t=t^a[j];
				if(t==k){
					cnt++;
					t=a[j+1];
					j++;
				}
			}
		}
		ans=max(ans,cnt);
		cnt=0;
	}
	cout<<ans;
}

