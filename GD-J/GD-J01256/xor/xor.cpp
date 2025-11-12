#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+6;
int n,k,a[N],pp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	for(int i = 2;i<=n;i++){
		if(cnt==k){
			pp++;
		}else{
			cnt=cnt^a[i];
		}
	}
	if(cnt==k){
		pp++;
	}
	cout<<pp;
	return 0;
}
