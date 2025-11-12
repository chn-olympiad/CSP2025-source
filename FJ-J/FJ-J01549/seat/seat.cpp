#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int mark=b[1];
	int w;
	sort(b+1,b+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==mark){
			if(i<=n) {
				if(i==n)
					cout<<1<<' '<<n;
				else cout<<1<<' '<<i%n;
				break;
			}
			else if(i>=n+1&&i<=n*2){
				cout<<2<<' '<<n-(i%n)+1;
				break;
			}
			else if(i>=n*2+1&&i<=n*3){
				cout<<3<<' '<<i%n;
				break;
			}
			else if(i>=n*3+1&&i<=n*4){
				cout<<4<<' '<<n-(i%n)+1;
				break;
			}
			else if(i>=n*4+1&&i<=n*5){
				cout<<5<<' '<<i%n;
				break;
			}else if(i>=n*5+1&&i<=n*6){
				cout<<6<<' '<<n-(i%n)+1;
				break;
			}
			else if(i>=n*6+1&&i<=n*7){
				cout<<7<<' '<<i%n;
				break;
			}
			else if(i>=n*7+1&&i<=n*8){
				cout<<8<<' '<<n-(i%n)+1;
				break;
			}
			else if(i>=n*8+1&&i<=n*9){
				cout<<9<<' '<<i%n;
				break;
			}
			else if(i>=n*9+1&&i<=n*10){
				cout<<10<<' '<<n-(i%n)+1;
				break;
			}
		}
	}
return 0;	
}