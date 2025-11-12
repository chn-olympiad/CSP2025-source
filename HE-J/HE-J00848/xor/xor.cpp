#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
long long a[N];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<0;
		}
		else if((a[i]>=0&&a[i]<=1)){
			cout<<0;
		}
	}
	return 0;
	
}
