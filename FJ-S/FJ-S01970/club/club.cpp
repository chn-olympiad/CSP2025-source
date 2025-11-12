#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int maxa=0;
int a[N+5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[i];
			}
		}
	}
	int sum=n/2;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4

4 2 1
3 2 4                       18
5 3 4
3 5 1

4

0 1 0
0 1 0
0 2 0                       4
0 2 0 

2
10 9 8                      13
4 0 0
*/
