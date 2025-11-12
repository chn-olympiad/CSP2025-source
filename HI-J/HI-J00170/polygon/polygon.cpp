#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r"stdin);
	freopen("polygon.out","w"stdout);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int o=0;
	sort(a+1,a+n+1);
	int sum;
	for(int m=1;m<=n;m++){
		for(int j=3;j<n;j++){
			sum=0;
			for(int i=1;i<=j;i++){
				sum+=a[i];
			}	
			if(sum>a[j+1]){
				o++;
			}
		}
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
