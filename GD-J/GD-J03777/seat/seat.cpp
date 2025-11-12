#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000];//¸Ä·¶Î§ 
long long b[110][110];
long long wz;
long long j=1;
long long k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a0=a[0];
	sort(a,a+(n*m),greater<int>());
	/*
	for(int i=0;i<n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	*/
	int ll=1;
	for(int i=0;i<m;i++){
		if(ll%2!=0){
			for(int j=0;j<n;j++){
				b[j][i]=a[k];
				k++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				b[j][i]=a[k];
				k++;
			}
		}
		ll++;
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==a0){
			cout<<j+1<<" "<<i+1;
			}
		}
	}


	
	return 0;
} 
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

3 5
6 2 5 7 8 9 11 22 55 66 84 1 23 45 15 
*/
