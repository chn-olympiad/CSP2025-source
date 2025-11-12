#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	int a[500001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m=0;
	int j;
	for(int i=0;i<n;){
		m=0;
		m+=a[i];
		for(j=i+1;j<n;j++){
			if(m==k||m+k==0){
				break;
			}
		    if(m<k){
				if(a[j]-m==k){
					m=a[j]-m;
				}else{
					m+=a[j];
				}
				
			}else{
				m-=a[j];
			}
		}
		if(m==k||m+k==0){
			cnt++;
			i=j;
		}else{
			i++;
		}
	}
	cout<<cnt;
	return 0;
} 
