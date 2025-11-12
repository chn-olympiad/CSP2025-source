#include<bits/stdc++.h>
using namespace std;

int n,m,a[105][105],b[1000],tt;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>> m;
	int t1=1;
	for(int i =1;i<=n*m;i++){
		cin >> b[i];
	}
	tt=b[1];
	sort(b+1,b+n*m+1);
	for(int i =1;i<=n;i++){
		if(i%2==1){
			for(int j =1;j<=m;j++){
				a[i][j]=b[t1];
				t1++;
			}
		}
		else{
			for(int j =m;j>=1;j--){
				a[i][j]=b[t1];
				t1++;
			}
		}
	}
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==tt)cout << i<<' '<<j;
		}
	} 
	
	
	
	return 0;
}
