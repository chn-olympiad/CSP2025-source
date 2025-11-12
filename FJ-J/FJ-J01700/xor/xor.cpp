#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a[100000],k,n,s=0,t=0,i;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(a[i]==k){
			s++;
			t=0;
		}
		if(a[i]!=k){
			t=t^a[i];
			if(t==k){
				s++;
				t=0;
			}
		}
		
	}
	cout<<s;
	return 0;
}
