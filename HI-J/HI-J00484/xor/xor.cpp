#include<bits/stdc++.h>
const int N=5*1e5+5;
int a[N];
using namespace std;
int main(void){
	freopen(" xor.in ","r",stdin);
	freopen("xor.out ","w",stdout);	
	int n,k;
	cin>>n>>k;
	int b=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		
	}
	int sum=1;
	int i=1;
	while(i<=n){
	
		int ans=a[i];
		if(ans==k){
			b+=1;
		
			i++;
			continue;
		}
		for(int j=i+1; j<=n; j++){
			ans=(ans+a[j])%2;
			if(ans==k){
			
				i=j+1;
				b+=1;
				break;
			}
		}
		
		
	}
	cout<<b;
	return 0;
}

