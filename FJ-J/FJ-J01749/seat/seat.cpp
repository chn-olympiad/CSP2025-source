#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[111],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b = a[0];
	sort(a,a+n*m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i*m+j]==b){
				if((m-i)%2==0){
					cout<<m-i<<" "<<j+1;
				}
				else{
					cout<<m-i<<" "<<n-j;
				}
				b = -1;
				break;
			}
		}
		if(b==-1){
			break;
		}
	}
	return 0;
}
