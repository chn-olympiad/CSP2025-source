#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
// 	freopen ("seat.in","r",stdin);
//	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	int snum=n*m;
	for(int i=1;i<=snum;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+snum+1);
	for(int i=1;i<=snum;i++){
		if(a[i]==k){
			int sm=i%m+1,sn=i%n;
			cout<<sm<<" ";
			if(sm%2==0){
				cout<<sn;
			}else{
				cout<<n+1-sn;
			}
			return 0;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
}
