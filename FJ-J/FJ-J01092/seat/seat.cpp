#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int ww;
	cin>>ww;
	a[0]=ww;
	for(int j=1;j<n*m;j++){
		cin>>a[j];
	}
	sort(a,a+n*m);
	int i=n*m-1,ss=0;
	while(a[i]!=ww){
		i--;
	}
	i++;
	if(i==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int k=1,j;
	for(;i>0;){
		for(j=0;j<m;j++){
			for(;k<n;k++){
				i--;
			}
			for(;k>0;k--){
				i--;
			}
	}
	}
	cout<<j<<" "<<n-k;
	return 0;
}
