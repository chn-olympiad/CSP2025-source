#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b[2]={1,1};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]>a[1]){
				if(b[0]%2==0){
					b[1]--;
					if(b[1]<1){
						b[0]++;
						b[1]=1;
					}
				}
				else{
					b[1]++;
					if(b[1]>n){
						b[0]++;
						b[1]=n;
					}
				}
			}
		}
	}
	cout<<b[0]<<" "<<b[1];
	return 0;
}
