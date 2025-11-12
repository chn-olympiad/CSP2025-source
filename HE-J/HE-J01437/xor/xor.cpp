#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				h++;
			}
		}
	}
	if(h=2){
		cout<<h;
	}else{
		cout<<1;
	}
	return 0;
}
