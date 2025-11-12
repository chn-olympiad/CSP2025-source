#include<bits/stdc++.h>
using namespace std;
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	int n,m,h=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
		}
	for(int i=2;i<=n*m;i++){
		if(b[1]<b[i]){
			h+=1;
		}
	}
	int a=1;
	while(h>=m){
		if(h>=m){
			h=h-m;
			a++;
		}
	}
	if(a%2==0){
		h=m-h-1;
	}
	cout<<a<<" "<<h+1;
	return 0;
}
