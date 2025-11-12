#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int s[15][15],a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int j=1,k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			while(j<=n){
				s[j][i]=a[k];
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
				j++;
			}
			j=n;
		}
		else{
			while(j>=1){
				s[j][i]=a[k];
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
				j--;
			}
			j=1;
		}
	}
	return 0;
}
