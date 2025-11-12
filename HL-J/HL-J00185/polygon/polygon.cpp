#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
  	freopen("polygon.out","w",stdout);
  	long long n,sum=0,count=0,max=0;
  	cin >> n;
  	long long oo[n],op[n];
  	for(int i=0;i<=n;i++) cin>>oo[i];
  	for(int q=3;q<=n;){
	   	for(int i=1;i<=n-q+1;i++){
  			for(int j=i;j<=i+q-1;j++){
  				sum+=oo[j];
  				op[j]=oo[j];
			}
			max=op[0];
			for(int i=1;i<n;i++){
				if(max<op[i]) max=op[i];
			}
			if(sum>max) count++;	
			max=0;
		}
		q++;
	}
	count=count%998244353;
	cout<<count;
	
  	
  	
  	fclose(stdin);
  	fclose(stdout);
  	return 0;
}