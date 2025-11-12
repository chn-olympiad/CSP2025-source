#include<bits/stdc++.h> 
using namespace std;
const int N=1e5;
int b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,s=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	for (int i=2;i<=n;i++){
		b[i]=b[i-1]+b[i];
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (b[i]-b[j-1]==k){
				s++;
			}
		}
	}
	
	cout<<s;
	return 0;
}
