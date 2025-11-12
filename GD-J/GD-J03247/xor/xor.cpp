#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n==1){
			if(a[1]==0)cout<<1;
			else cout<<0;
			return 0;
		}
		int anss=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)anss++;
		}
		cout<<anss;
		return 0;
	}
	return 0;
}

