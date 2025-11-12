#include<bits/stdc++.h>
using namespace std;
int n,k,a,b[500010],ans,in=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==k)
			ans++,in=i+1;
		else 
			for(int j=in;j<i;j++){
				b[j]=b[j] xor a;
				if(b[j]==k){
					ans++,in=i+1;
					break;
				}	
		}b[i]=a;
	}
	cout<<ans;
	return 0;
}

