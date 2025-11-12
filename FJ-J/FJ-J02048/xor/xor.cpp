#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x^a[i-1];
	}
	x=0;
	for(int i=1;i<=n;i++){
		int y=a[i]^k;
		for(int j=x;j<i;j++){
			if(a[j]==y){
				x=i;
				s++;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
