#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	int n,k,m=0,o,l=0,x=0,p=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			m+=1;
			o=i;for(int i=1;i<o;i++){
				l+=a[i];
				if(l==k){
					m+=1;
					l=0;
			}
		}
			for(int j=o+1;j<=n;j++){
				x+=a[j];
				if(x==k){
					m+=1;
					x=0;
					
			}
			
		}
		}
		
		
		
	}
	cout<<m;
	return 0;
}