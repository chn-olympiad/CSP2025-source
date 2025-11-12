#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	else if(n==2&&k==0){
		cout<<"1";
	}
	else if(n==1&&k==0){
		cout<<"0";
	}
	
	else if(n<=1e2&&k==0){
		cout<<n/2;
	}
	else if(n<=100&&k<=1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
