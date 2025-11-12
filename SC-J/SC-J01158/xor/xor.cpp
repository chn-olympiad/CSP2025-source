#include<bits/stdc++.h>
using namespace std;
int a[200005];
int fi=0,se=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)fi++;
		else se++;
	}
	if(k==0){
		if(fi%2==0){
			cout<<se+fi/2;
		}else{
			cout<<0;
		}
	}else{
		cout<<fi;
	}
	return 0;
}