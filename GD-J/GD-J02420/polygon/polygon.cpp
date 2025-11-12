#include<bits/stdc++.h>
using namespace std;
int n,m=0; 
int l[10020];
int Max;
int aMax;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=3;i<=n;i++){
		Max=0;
		aMax=0;
		for(int j=1;j<=i;j++){
			Max=max(Max,l[j]);
			aMax+=l[j];
		}
		if(aMax>Max*2){
			m++;
		}
	}
	cout<<m*3;
	return 0;
} 
