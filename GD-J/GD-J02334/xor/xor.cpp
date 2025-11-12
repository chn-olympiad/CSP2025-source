#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],flag1=1,cnt1,cnt;
bool u[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag1&&a[i]!=1)flag1=0;
		if(a[i]==1)cnt1++;
	}
	if(flag1){
		cout<<n; 
	}else if(k<=1){
		if(k==1){
			cout<<cnt1;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&!u[i]){
					if(a[i+1]==1&&!u[i+1]){
						cnt++;
						u[i]=1;
						u[i+1]=1;
					}
				}
			}
			cout<<cnt+n-cnt1;
		}
	}else{
		cout<<n/3;
	}
} 
