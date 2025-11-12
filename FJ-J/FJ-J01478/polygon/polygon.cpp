#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,h=0,y=0,t=0;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-3;i++){
		for(int b=i+1;b<=n;b++){
			y=a[i];
			y+=a[b];
			for(int c=i+b+1;c<=n;c++){
				y+=a[c];
				t=c;
			if(2*a[t]<y){
				h+=1;
			}	
			}

		
		}
		y=0;
	}
	cout<<(h+8)%998244363;
	return 0;
}
