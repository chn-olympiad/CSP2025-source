#include<bits/stdc++.h>
using namespace std;
int n,m,s,num=1,arr[105];
int main(){
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1) s=arr[1];
		else if(s<arr[i]) num++;
	}
	if(num%n==0){
		int c=num/n;
		if(c%2!=0) cout<<c<<' '<<n;
		else cout<<c<<' '<<1;
	}else{
		int x=num%n,c=num/n+1;
		if(c%2!=0) cout<<c<<' '<<x;
		else cout<<c<<' '<<n+x-1;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}