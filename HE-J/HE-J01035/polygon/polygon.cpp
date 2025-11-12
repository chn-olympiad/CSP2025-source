#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
bool cmp(int x,int y){
	return x>y;
}
int a[1000000];
bool f=true;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1){
			f=false;                                                
		}
	}
	if(f){                                            
		cout<<n-2;                                              
		return 0;                                           
	}                                        
	if(n==3){
		sort(a+1,a+1+n,cmp);          
		if(a[1]<a[3]+a[2]){                                       
			cout<<1;
			return 0;                                                                  
		}else{                                    
			cout<<0;                       
			return 0;                                    
		}                                           
	}                                                    
	                                                          
	return 0;
}

