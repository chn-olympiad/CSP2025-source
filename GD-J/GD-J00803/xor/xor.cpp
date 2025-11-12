#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[500005];
int li[500005];

void solve1(){
	int l=1,r=1;
	int ans=0;
	while(r<=n){
		for(int i=l;i<=r;i++){
			if((li[r]^li[i-1])==k){
				ans++;
				l=r+1;
				break;
			}
		}r++;
	}cout<<ans;
	return;
} 



int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		li[i]=arr[i]^li[i-1];
	}
	solve1();
	
	
	
	return 0;
} 
