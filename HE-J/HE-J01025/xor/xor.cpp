#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int n,k,a[500000],sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sum++;
			continue;
		}
		else{
			int num=0;
			int c=i;
			while(1){
				num=num^a[c];
				if(num==k){
					i=c;
					sum++;
					break;
				}
				c++;
			}
		}
	}
	cout<<sum;
	return 0;
}
