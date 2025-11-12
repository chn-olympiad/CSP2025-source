#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[101],tmp,j=1,k=1;
	bool f=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tmp=a[1];
	stable_sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==tmp){
			cout<<j<<' '<<k;
			return 0;
		}
		if(!f){
			k++;
			if(k==n+1){
				k=n;
				j++;
				f=1;
			}
		}
		else{
			k--;
			if(k==0){
				k=1;
				j++;
				f=0;
			}
		}
	}
	return 0;
}
