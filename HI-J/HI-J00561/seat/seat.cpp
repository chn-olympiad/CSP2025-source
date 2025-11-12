#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	int r=b[1],sum=0;
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		//cout << b[i] << endl;
		sum++;
		if(b[i]==r){
			 //cout << sum << endl;
			break;
		}
	}
	int j=sum/m;
	//cout << sum << endl;
	cout << sum/m+1 << " ";
	if(sum<=m)cout << sum << " ";
	else {
		if((sum/m+1)%2==0){
			cout << sum-m*j+m-1;
		}
		else cout << sum-m*j;
	}
} 
