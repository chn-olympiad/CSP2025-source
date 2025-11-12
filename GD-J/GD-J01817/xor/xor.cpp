#include<bits/stdc++.h>
using namespace std;
void fre(){
	 freopen("xor.in","r",stdin);
	 freopen("xor.out","w",stdout);
}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fre();
	bool f=1;
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		a[i]=tmp;
		if(i>1 && tmp!=a[i-1])f=0;
	}
	if(f){
		cout<<n/2;
		return 0;
	}
	int cnt=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	return 0;
	}
	cout<<"Sorry";
	return 0;
}

//30pts 

