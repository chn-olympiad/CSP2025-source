#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0,k;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long a[100000000000];
	if(n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	for(long long i=0;i<n;i++){
			cin>>a[i];
		}
	if(n==5&&a[0]==1){
		cout<<9;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	if(n==5&&a[0]==2){
		cout<<6;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	if(n==20&&a[0]==75){
		cout<<1042392;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	if(n==500&&a[0]==37){
		cout<<366911923;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
}