#include<bits/stdc++.h>
using namespace std;
long long n,m,a,s[1000],w,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	} 
	a=s[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<n*m;j++){
			if(s[j]<s[j+1]){
				swap(s[j],s[j+1]);
			}
		}	
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			w=i;
		}
	}
	x=(w-1)/n+1;
	if(x%2==1){
		y=(w-1)%n+1;
	}
	else{
		y=1-w+n*x;
	}
	cout<<x<<' '<<y;
	return 0;
}