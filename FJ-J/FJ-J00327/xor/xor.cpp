#include<bits/stdc++.h>
using namespace std;
int a[500001],f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,w=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]){
			w=0;
		}
	}
	if(w){
		cout<<n/2<<endl;
	}
	else if(!w){
		int s=0;
		for(int i=1;i<=n;i++){
			f=f+a[i];
			if(f%2==k||a[i]==k){
				f=0;
				s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}

