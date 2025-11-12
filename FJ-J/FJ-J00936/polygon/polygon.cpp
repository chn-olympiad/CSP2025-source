#include<bits/stdc++.h>                                                           
using namespace std;
long long a[10001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxm=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxm){
			maxm=a[i];
		}
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),max(a[2],a[3]))){
			cout<<1;  
			return 0;
		}
		else{
			cout<<0;
			return 0;
	 	}
	}                                                    
	else if(maxm==1){
		cout<<(n-2)*(n-3)/2; 
		return 0;
	}
	return 0;
	fclose(stdin);                                                           
	fclose(stdout);    
}
