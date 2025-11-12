#include<bits/stdc++.h>
using namespace std;
int const N=5e5+100;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=1,sum=0,cmt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				cmt++;
				sum=0;
				i=j;
				break;
			}		
		}		
	}

		
	cout<<cmt;

	return 0;
} 
