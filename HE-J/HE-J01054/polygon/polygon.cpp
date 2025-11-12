#include<bits/stdc++.h>
using namespace std;
int a[100],num=0;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ven,ma;
	for(int i=1;i<=n;i++){
		ven=0;
		ma=INT_MIN;
		for(int j=i;j<=n;j++){
			ven+=a[j];
			ma=max(a[j],ma);
			if((j-i+1)>=3 && ven>2*ma){
				num++;
			}
		}
	} 
	cout<<num;
	return 0;
}

