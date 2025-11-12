#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int s=0;
		for(int r=l;r<=n;r++){
			s=s^a[r];
			if(s==k){
				cnt++;
				l=r;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
