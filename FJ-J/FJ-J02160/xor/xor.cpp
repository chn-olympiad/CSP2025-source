#include<bits/stdc++.h>
using namespace std;
int n,k,zer,oe,noww;
bool fla;
int sum;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			zer++;
			fla=false;
		}
		else if(a[i]==1)oe++;
		if(a[i]==1){
			if(a[i-1]==1){
				if(fla){
					fla=false;
					zer++;
					continue;
				}
			}
			fla=true;
		}
	}
	if(k==1){
		cout<<oe;
		return 0;
	}
	else if(k==0){
		cout<<zer;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			noww^=a[i];
			if(noww==k){
				sum++;
				noww=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
