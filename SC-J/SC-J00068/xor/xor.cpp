#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a,b,sum;
	cin>>a>>b;
	long long z[a+1];
	for(int i=1;i<=a;i++){
		cin>>z[i];
	}
	vector<int> e,r; 
	for(int i=2;i<a;i++){
		long long d=z[i-1];
		for(int j=i;j<=a;j++){
			for(int k=i;k<=j;k++){
				d=d^z[k];
			}
			if(b==d)
			sum++;	
		}
	}
	cout<<sum/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 