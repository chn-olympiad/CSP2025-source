#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}	
	
	if(k==1)
	cout<<b[1]+b[0]/2;
	else
	cout<<b[0]+b[1]/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 