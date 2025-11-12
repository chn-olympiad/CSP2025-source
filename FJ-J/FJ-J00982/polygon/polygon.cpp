#include <bits/stdc++.h>
using namespace std;
const int max1=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	int s=0,s2=0;
	long long o=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		s+=a[i];
		if(s2>a[i]){
			s2=a[i];
		}
	}
	s2*=2;
	if(n==3){
		if(s>s2){
			cout<<1;
		}else{
			cout<<0;
		}
	} 
	/*for(int p=3;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
					
			} 	
		} 
	}*/
	cout<<1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
