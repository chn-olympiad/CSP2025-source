#include <bits/stdc++.h>
using namespace std;
int n, a[5005],lon,point,x,b[5005],cha,c[1005];
double ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		point=a[i];
		for (int j=1;j<=n;j++){
			if (a[j]<point){
				lon+=a[j];
				b[j]=1;
				x++;
			}
			if (x>=2){
				if(lon>point){
					ans++;
				}
			}
		}
		lon=0;
		for (int g=1;g<=n;g++){
			b[g]=0;
		}
	}
	cout<<ans;
	return 0;
}
