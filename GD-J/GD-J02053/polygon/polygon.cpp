#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,b,c,sum=0,ji=0,k;
	cin>>n;
	int a[n],i,j;
	if(n==3){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+n);
		if(a[0]+a[1]+a[2]>2*a[2]){
			cout<< 1;
		}
	}else if(n>3){
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=3;i<n;i++){
			for(j=0;j<i-1;j++){
				ji=a[j];
				if(ji+a[j+1]>a[i]){
					sum+=i-1-j;
					continue;
				}
				for(k=j+2;k<i;k++){
					ji+=a[k];
					if(ji>a[i]){
						sum+=i-1-k;
						break;
					}	
				}
			}
		}
		cout<< sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
