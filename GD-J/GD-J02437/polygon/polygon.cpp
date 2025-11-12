#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long m,z=0;cin >> m;int a[m];
	for(int i=0;i<m;i++){
		cin >> a[i];
	}for(int i=0;i<m-2;i++){
		if(2*a[i+2]<a[i]+a[i+1]+a[i+2]){
			z++;
		}
	}
	cout << z;
	return 0;
}
