#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[103],z,f;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	z=s[1];
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(s[i],s[n*m-i+1]);
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==z){
			f=i;
			break;
		}
	}
	while(1){
		for(int y=1;n>=y;y++){
			for(int x=1;m>=x;x++){
				if(x%2){
					z=(x-1)*n+y;
				}
				else{
					z=(x-1)*n+n-y+1;
				}
				if(z==f){
					cout<<x<<' '<<y;
					return 0;
				}
			}
		}
	}
	return 0;
} 

