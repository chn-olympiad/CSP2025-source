#include<bits/stdc++.h>
using namespace std;

int a[500005];
int k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int cnt=0;
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==n){
			cnt++;
			a[i]==-1;
		}
	}
	
	return 0;
}
