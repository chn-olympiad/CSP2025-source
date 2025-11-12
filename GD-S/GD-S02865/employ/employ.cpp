#include<bits/stdc++.h>
using namespace std;
int b[10005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;string a;
	cin>>n>>m;cin>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
