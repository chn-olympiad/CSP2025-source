#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=1,x;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(i==0&&j==0)cin>>x;
		else{
			int t;
			cin>>t;
			if(t>x)ans++;
		}
	}
}
int k=ceil((ans*1.00)/(n*1.00));
	cout<<k;
	cout<<" ";
	if(k%2==1){
		cout<<ans-(k-1)*n;
	}
	else cout<<n-(ans-(k-1)*n)+1;
return 0;
}
