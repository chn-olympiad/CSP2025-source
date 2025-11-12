#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> A;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	A=vector<int>(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<sqrt(n); 
	return 0; 
}
