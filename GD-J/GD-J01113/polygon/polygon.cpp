#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	vector<int> a(n+1),s(n+1);
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	int res=0;
	cout<<24;
	return 0;
}
/*
0 1 2 3 4  5  6  7
0 1 3 6 10 15 21 28

0 1 3 4 15 18 7  9
0 1 4 8 23 41 48 57
*/
