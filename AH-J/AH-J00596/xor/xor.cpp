#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	long long cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==m){
				l=r;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
