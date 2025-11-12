#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    if(k==0){
    	for(int i=1;i<=n;i++){
    		if(a[i]==0){
    			sum++;
			}else{
				if(a[i+1]==1){
					sum++;
					i++;
				}
			}
		}
		cout << sum ;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
		}
		cout << sum ;
	}
	return 0;
}
//相同为0，不同为1；
 
