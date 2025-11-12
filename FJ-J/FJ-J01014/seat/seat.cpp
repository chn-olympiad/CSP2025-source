#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s2[400];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s2[i];
	}
	int xm=s2[0];
	sort(s2,s2+n*m);
	int ans=n*m-1,zt=0,h=0;
	while(ans>-1){
		switch(zt){
			case 0:
				for(int i=0;i<n;i++){
					if(s2[ans]==xm){
						cout<<h+1<<" "<<i+1;
						return 0;
					}
					ans--;
				}
				break;
			case 1:
				h++;
				if(s2[ans]==xm){
					cout<<h+1<<" "<<n;
					return 0;
				}
				break;
			case 2:
				for(int i=n-1;i>-1;i--){
					if(s2[ans]==xm){
						cout<<h+1<<" "<<i+1;
						return 0;
					}
					ans--;
				}
				break;
			case 3:
				h++;
				if(s2[ans]==xm){
					cout<<h+1<<" "<<1;
					return 0;
				}
				break;
				
		}
		zt++;
		zt%=4;
	}
	return 0;
}
