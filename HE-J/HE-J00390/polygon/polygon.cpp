#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,num=0;
	cin>>n;
	if(n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	if(a[0]+a[1]+a[2]>2*a[2])cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
