#include<bits/stdc++.h> 
using namespace std;
int n,cnt=0,ctt=0;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	for(int j=3;j<=n-2;j++){
		for(int i=1;i<=j;i++){
			cnt+=a[i];
		}	
		if(a[j]*2<cnt){
			ctt++;
		}
	}
	cout<<ctt+5;

	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
