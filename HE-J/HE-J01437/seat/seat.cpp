#include<bits/stdc++.h>
using namespace std;
int a[10010],h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				h+=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<h<<" ";
	}
	return 0;
}
