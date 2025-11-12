#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int x=0,y=n-1;
	long long ans=0,num=0,num1=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				ans=ans^a[k];
			}
			num1=j-i+1;
			if(ans==k&&num1>num) num=num1;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
