#include<bits/stdc++.h>
using namespace std;
int s,v,da;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
		for(int i = 0;i<=n-k;i++){
			for(int j = i;j<i+k;j++){
				s = s+a[j];
				da = max(a[j],da);
			}
			
		}
		if(s>da*2){
			v++;
		}
		v = v%998244353;
	}
	cout<<v;
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
