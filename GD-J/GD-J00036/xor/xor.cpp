#include <bits/stdc++.h> 
using namespace std;
long long a[1000005];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cur=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			cur=0;
			continue;
		}
		cur=cur^a[i];
		if(cur==k){
			cnt++;
			cur=0;
		}
	}
	cout<<cnt;
	return 0;	
}
