	#include <bits/stdc++.h>
	using namespace std;
	long long N=1e5+10;
	int main(){
	freopen("polygon.in","n,a[n]",stdin);
	freopen("polygon.out","j",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=0;
	int max=0;
	for(int i=1;i<=n;i++){
	b+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			max=a[i+1];
		}
		else if(a[i>a[i+1]]){
			max=a[i];
		}
			}
  int pormax=0;
  pormax=max*2;
  int j=0;
  int nemx;
  int newnp;
	if(n>=3){
	for(int i=1;i<=n;i++){
		for(int x=1;x<=i;x++){
			a[x]+=a[x+1];
			
			newnp=a[x];
			if(a[x]<a[x+1]){
				
				nemx=a[x+1];
			}
			else if(a[x]>a[x+1]){
				nemx=a[x];
			}
		}
		if(newnp>nemx*2){
			j++;
		}
	}
	}
	j=j%998244353;
	cout<<j;
return 0;
	}
	
