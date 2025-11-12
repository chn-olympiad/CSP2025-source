#include<bits/stdc++.h>
using namespace std;
int n,a[10000],bs=3,cnt=0;
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(bs<=n){
		for(int i=1;i<=n-bs+1;i++){
			int h=0;
			for(int j=i;j<=i+bs-1;i++){
				h+=a[j];
			}
			cout<<h;
			if(a[i+bs-1]<h/2){
				cnt++;
			}
		}
		bs++;
	}
	cout<<cnt;
} 
