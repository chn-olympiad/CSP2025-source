#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];if(a[i]==k)t++;
	}
	cout<<t;
	fclose(stdin);fclose(stdout);
	return 0;
} 
