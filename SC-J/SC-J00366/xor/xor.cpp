#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fz(int n,int t,vector<int>&A){
	for(int i=t+1;i<n;i++)A[i]^=t;
	A.erase(A.begin(),A.begin()+t);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,ans=0;cin>>n>>k;
	vector<int>A(n),B(n);
	for(int &i:A)cin>>i;
	B[0]=A[0];
	for(int i=1;i<n;i++)B[i]=(B[i-1]^A[i]);
	while(!B.empty()){
		int i=0,t=0;
		for(;i<B.size();i++){
			if(B[i]==k){
				ans++;
				t=B[i];
				goto ok;
			}
			for(int j=i-1;j>=0;j--){
				if((B[i]^B[j])==k){
					ans++;
					t=B[i];
					goto ok;
				}
			}
		}
		ok:if(i==B.size())break;
		else fz(B.size(),t,B);
	}
	cout<<ans;
	return 0;
}