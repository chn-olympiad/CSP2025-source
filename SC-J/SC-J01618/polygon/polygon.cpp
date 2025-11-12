#include <bits/stdc++.h>
using namespace std;
int n,a[10010],c=0;
int stick[10010],num=1;
int ma=INT_MIN; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
	}
	
	sort(stick+1,stick+n+1);
	while(num<=n){
		for(int i=1;i<=n-num;i++){
			int s=0; 
			for(int j=i;j<=i+num;j++){
				s+=stick[j];
				
				if(stick[j]>=ma){
					ma=stick[j];
				} 
			}
			for(int j=i+num+1;j<=n;j++){
				if(stick[j]>=ma){
					if(s+stick[j]>2*stick[j]){
						c++;
					}
				}else{
					if(s+stick[j]>2*ma){
						c++;
					}	
				}
			}
		}
		num++;
	}
	cout<<c;
	return 0;
}