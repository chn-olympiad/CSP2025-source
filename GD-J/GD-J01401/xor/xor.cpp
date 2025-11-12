#include<bits/stdc++.h> 
using namespace std;
int n,a[200005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				t++;
				i++;
			}
		}
	}else{
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				t++;
				i++;
			}
		}
	}
	cout<<t;
	return 0;
}

