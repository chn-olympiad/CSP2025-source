#include<bits/stdc++.h>
using namespace std;
int s[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int an=s[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(s[i]<s[j]) swap(s[i],s[j]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==an){
			if(i%n==0){
				
				x=i*1.0/n;
			}
			else{
				x=i*1.0/n+1;
				
			}
			if(x%2==0&&i%n==0) y=1;
			if(x%2==0&&i%n!=0) y=n-i%n+1;
			if(x%2!=0&&i%n==0) y=n;
			if(x%2!=0&&i%n!=0) y=i%n;
		}    
	}
	cout<<x<<" "<<y;
	return 0;
}
