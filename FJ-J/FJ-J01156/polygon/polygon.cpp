#include<bits/stdc++.h>
#define int long long
using namespace std;
int R[50005]={};
int A[50005]={};
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>R[i];
	}
	sort(R+1,R+1+n);
	for(int i=1;i<=n;i++){
		A[i]=A[i-1]+R[i];
	}
	int a=*max_element(R+1,R+1+n);
}
/*
5
2 2 3 8 10
*/
