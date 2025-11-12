#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s,ans;
bool t=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	while(t){
		t=false;
		int m=n;
		for(int i=s;i<m;i++){
			int cnt=0;
			for(int j=i;j<m;j++){
				cnt^=a[j];
				if(cnt==k){
					m=j;
					t=true;
				}
			}
		}
		if(t){
			s=m+1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
