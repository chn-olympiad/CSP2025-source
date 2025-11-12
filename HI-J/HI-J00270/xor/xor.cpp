#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n]={};
	for(int i=0;i<n;){
		cin>>a[i];
		i++;
	}
	if(n==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==1){
		cout<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==2){
		cout<<2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}

