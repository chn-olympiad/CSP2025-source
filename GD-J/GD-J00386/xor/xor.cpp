#include <iostream>
#include <algorithm>
using namespace std;

int n,k,mi=1,f;
int a[500010];
int s[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
//		cout<<s[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=mi;j--){
			if((s[i]^s[j-1])==k){
//				cout<<(s[i]^s[j-1])<<endl;
//				cout<<j-1<<" "<<i<<endl;
				f++;
				mi=i+1;
				break;
			}
		}
	}
	cout<<f;
	return 0;
}
/*
4 0
2 1 0 3
*/ 
