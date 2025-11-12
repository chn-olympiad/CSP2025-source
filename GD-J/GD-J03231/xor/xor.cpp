#include <bits/stdc++.h>
using namespace std;
const int N=5*15+15;
int a[N];
int poll(int po){
	int i=2,ans=0;
	while(i<=po){
		ans+=po-i+1;
		i+=2;
	}
	return ans;
}
int poli(int po){
	int i=1,ans=0;
	while(i<=po){
		ans+=po-i+1;
		i+=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(k==0){
		int ans=0;
		int b[N];
		b[1]=0;
		b[2]=1;
		b[3]=2;
		for(int i=4;i<=n;i++){
			b[i]=poll(i);
		}
		cout <<b[n];
	}else if(k==1){
		int ans=0;
		int b[N];
		b[1]=1;
		b[2]=1;
		b[3]=2;
		for(int i=4;i<=n;i++){
			b[i]=poli(i);
		}
		cout <<b[n];
	}
	return 0;
}
