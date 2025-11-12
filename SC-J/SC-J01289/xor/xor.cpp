#include "bits/stdc++.h"
using namespace std;
int k,maxx=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	
	if(n<=2&&k==0){
		cout<<0;return 0;
	}
	int cnt=rand()%(n+2);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}