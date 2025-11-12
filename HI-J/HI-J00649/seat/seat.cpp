#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,cnt=1,h,k=1;
	cin>>n>>m;
	int a[10000];
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			cnt++;
		}
	}
	if(cnt<=n){
	 cout<<k<<" "<<cnt; 
	 return 0;
	}
	else{
		for(int j=1;j;j++){
			cnt=cnt-n;
			k++;
			if(cnt<=n){
			   j=-1;
			}
		}
   }
        if(k%2==0){
			if(cnt=1) cnt=k;
			else{
				if(cnt=k) cnt=1; 
				else cnt=k-cnt;
			}
		}
	 cout<<k<<" "<<cnt;
	
	return 0;
}
