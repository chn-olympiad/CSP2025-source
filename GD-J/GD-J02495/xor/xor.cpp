#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[500005];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			flag=true;
		}
	}
	if(k==0&& (!flag)){
		cout<<n/2;
		return 0;
	}if(flag){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}else if(a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
			return 0;
		}else{
			cout<<n;
		}
		
	}
} 

//
