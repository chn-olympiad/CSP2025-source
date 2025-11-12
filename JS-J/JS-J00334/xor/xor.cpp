#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long x[500010];
long long f(long long a,long long b){
	return (a or b) and !(a and b);  
}
                                                                                       
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
 	cin>>n;
 	cin>>k;
  
 	int ff = 1;
	for(int i = 1;i <= n;i++){
		int xx;
		cin>>xx;
		if(xx != 1) ff=0;
		a[i] = xx;
		if(i == 1) x[i] = xx;
		else x[i] = f(x[i - 1],xx); 
	}
 
 
	if(ff){
		if(k == 0){
			cout<<n / 2;
			return 0;
		}else{
			cout<<n;
			return 0;
		}
	}else{
		int ans = 0;
		if(k == 1){
			for(int i = 1;i <= n;i++){
				if((a[i] == 1) ) ans++;
			}
		}else{
			for(int i = 1;i <= n;i++){
				if(a[i] == 0){
					ans++;
				}
				else if(a[i] == 1 and a[i + 1] == 1){
					ans++;
					a[i + 1] = -1;
				}
				
				
				 
			}		
		}	
		cout<<ans;
		return 0;
	}
	
	/*
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++) {
			int p;
			if(i != 1) p = x[j];
			else p = f(x[j],x[i - 1]);
			cout<<p<<" ";
			if(p == k){
				cout<<i<<" " <<j<<endl;
			}
		}
	}
	* */
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
