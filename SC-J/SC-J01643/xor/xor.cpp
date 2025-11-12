#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[10000],k,b,n,l=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b=a[i];
		for(int j=1;j<=n;j++){
			b=b^a[i];
			if(b==k){
				l++;
			    i=j+1;
			    continue;
			}
			if(b>=k){
				i=j+1;
				continue;
			}
		}
	}
	cout<<l;
	return 0;
}