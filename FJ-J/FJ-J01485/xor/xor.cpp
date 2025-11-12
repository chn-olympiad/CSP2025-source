#include<bits/stdc++.h>
using namespace std;
long long n,k,a,b[500005],t,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[i]=b[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=t;j--){
			int x=b[i]^b[j];
			if(x==k){
				t=i;
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}

