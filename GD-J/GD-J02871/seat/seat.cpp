#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,num,a[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k;
		a[k]++;
		if(i==1) t=k;
	}
	for(int i=100;i>=0;i--){
		if(i==t){
			num+=1;
			break;
		}
		num+=a[i];
	}
	if((num-1)/n%2==1) cout<<(num-1)/n+1<<" "<<n-(num-1)%n;
	else cout<<(num-1)/n+1<<" "<<num%n;
	return 0;
} 
