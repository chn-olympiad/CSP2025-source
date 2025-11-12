#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			l++;
			continue;
		}
		long long he=a[i];
		for(int j=i+1;j<=n;j++){
			he=he^a[j];
			if(he==k){
				i=j;
				l++;
				break;
			}
		}
	}
	cout<<l;
	return 0;
}
