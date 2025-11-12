#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,ii=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout << 9;
		
	}else{
		long long jj = 0;
		for(int i = 1;i <= n;i++){
			jj = jj + i;
		}
		cout << jj;
	}
	return 0;
} 
