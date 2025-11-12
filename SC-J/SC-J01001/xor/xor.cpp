#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5],r=n,cnt;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0) cout<<1;
	else{
		for(int l=0;l<n;l++){
//			cout<<1<<"\n";
			for(r=n;l<r;l--){
//				cout<<2<<"\n";
				int noan;
				for(int i=l;i<r;i++){
//					cout<<3<<"\n";
					noan=noan^a[i];
				}
				if(k==noan){
//					cout<<4<<"\n";
					cnt++;
				} 
			}
		}
		cout<<cnt;
	} 
	return 0;
}