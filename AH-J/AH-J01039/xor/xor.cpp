#include<bits/stdc++.h>
using namespace std;

long long n,k,a[10000010],cnt,ans;
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}else{
			ans++;
		}
	}
	if(k==0){
		if(ans%2==0){
	    	cout<<cnt+ans/2;
	    }else{
		    cout<<cnt+(ans-1)/2;
	    }
	}else if{
		cout<<(n-cnt+ans)/2;
	}


    return 0;
}
