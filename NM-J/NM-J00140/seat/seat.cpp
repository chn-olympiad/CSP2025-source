#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	int o=n*m;
	sort(a+1,a+o+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int sum=0;
			for(int j=1;j<=m;j++){
				if(j%2!=0){
					for(int k=1;k<=n;k++){
						sum++;
						if(sum==i){
							cout<<j<<" "<<k<<endl;
							return 0;
						}
					}
				}else{
					for(int k=n;k>=1;k--){
						sum++;
						if(sum==i){
							cout<<j<<" "<<k<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}
