#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[100001],cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cnt++;
			}else if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
		}
	}else if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt++;
			}else if(a[i]+1==a[i+1]||a[i]-1==a[i+1]){
				cnt++;
				i++;
			}
		}
	}else{
		cnt=1;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
} 
