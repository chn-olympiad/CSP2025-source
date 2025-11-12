#include<bits/stdc++.h>
using namespace std;
int a[1000],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])s++;
	}
	int h=(s-1)/n;
	if(h&1){
		cout<<h+1<<' '<<n-(s-h*n)+1;
	}else{
		cout<<h+1<<' '<<s-h*n;
	}
	return 0;
} 
