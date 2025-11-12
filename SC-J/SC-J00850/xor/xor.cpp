#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,t=0;
	string a,wz="";
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]-'0';
	}
	for(int i=1;i<=n;i++){
		if((int)a[i]==k){
			t++;
			wz[t]=i;
		}
	}
	wz[t+1]=n+1;
	int up=0,s=1;
	for(int i=1;i<=n+1;i++){
		if(up==k){
			t++;
			up=0;
		}else  if(i==(int)wz[s]){
			s++;
			up=0;
		}else if(i!=wz[s]){
			up=up^a[i];
		}
	}
	cout<<t;
}