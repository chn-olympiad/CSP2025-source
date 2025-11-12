#include <bits/stdc++.h>
using namespace std;

const int N=5e5+50;
int n[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sn,k;
	int ans=0;
	cin>>sn>>k;
	for(int i=0;i<sn;i++){
		cin>>n[i];
	}
	for(int i=0;i<sn;i++){
		int cnt=0;
		for(int j=i;j<sn;j++){
			cnt^=n[j];
			if(cnt==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 