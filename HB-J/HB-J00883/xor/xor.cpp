#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[200005],f=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) f=1;
	}
	if(f==0&&k==0){
		cout<<n/2;
	}else if(f==0&&k==1){
		cout<<n;
	}else if(f==1&&k==0){
		int cnt=0;int t=0;
		for(int i=0;i<n;i++){
			if(t==2){
				t=0;
				cnt++;
			}
			if(a[i]==1){
				t++;
			}
			
		}
		if(t==2)cnt++;
		cout<<cnt;
	}else if(f==1&&k==1){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
