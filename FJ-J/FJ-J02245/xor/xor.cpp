#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	bool A=true,B=true;
	cin>>n>>k;
	vector<int> a(n);
	for(auto&i:a){
		cin>>i;
		if(i!=1) A=0;
		if(i>1) B=0;
	}
	if(A){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		else cout<<0;
	}else if(B){
		if(k>1) cout<<0;
		//cout<<"k="<<k<<endl;
		for(int l=0;l<n;l++){
			//cout<<"a[l]="<<a[l]<<endl;
			if(a[l]==k) cnt++/*,cout<<"l="<<l<<endl*/;
			else if(l<n-1&&a[l]^a[l+1]==k) cnt++,l++;
		}
		cout<<cnt;
	}
	return 0;
}
