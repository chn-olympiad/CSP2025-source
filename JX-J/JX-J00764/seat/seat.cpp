#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
int a[105];
int seat[11][11];


int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	int len = n*m;
	int t = 0;
	int c,r;
	int R = a[0];
	sort(a,a+len);
	for(int i = m-1;i>=0;i--){
		if(i %2 != 0){
			for(int j = 0;j<n;j++){
				seat[j][i] = a[t];
				t++;
				
			}
		}else{
			for(int j = m-1;j>=0;j--){
				seat[j][i] = a[t];
				t++;
				
				
			}
		}
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(seat[i][j] == R){
				c = i;
				r = j;
				break;
			}
		}
		
	}
	cout <<r+1<<' '<<c+1;
	return 0;
}

