#include<bits/stdc++.h>
using namespace std;

int h[105];

int main(){
	profest("xor.in","r",stdin);
	profest("xor.out","w",stdout);
	int n=0,m=0,a=0,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	sort(h+1,h+1+n);
	for(int i=1;i<=n;i++){
		if(h[i]%2==0){
			h[i]++;
		}else{
			h[i]--;
		}
	}
	for(int i=n;i>=2;i--){
		if(h[i]==h[i-1]){
			cout<<h[i];
		}
	}
	
	return 0;
}
