#include <bits/stdc++.h>
using namespace std;

//10 point for side A
//10-15 point for side B
const int N=1e6+1;
int n,k,sum=0,rr=0;
int a[N];
bool check(){
	for(int i=0;i<n;i++){
		if(a[i]==0){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0||i==n-1){
			rr+=(ans/2);
			sum++;
			f=false;
			ans=1;
		}
		else if(a[i]==1&&f==true){
			ans++;
		}
		else if(a[i]==1&&f==false){
			f=true;
			ans=1;
		}
	}
	if(k==0&&check()){
		cout<<n/2;
	}
	else if(k==1&&check()){
		cout<<n;
	}
	else if(k==1&&!check()){
		cout<<n-sum;
	}
	else{
		cout<<sum+rr;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
