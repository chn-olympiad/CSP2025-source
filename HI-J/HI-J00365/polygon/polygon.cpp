#include<bits/stdc++.h>
using namespace std;
int n,num[5001],sum=0,temp1,temp2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	for(int x=1;x<=n*n;x++){
		temp1 = num[x],temp2 = 0;
		for(int y=x+1;y<=n;y++){
			temp1 = num[y]+temp1;
			temp2 = (max(num[y-1],num[y]),temp2);
		}
	
		if(temp1 > temp2*2)sum = sum + 1;
	
	}
	cout << sum;
	return 0;
}
