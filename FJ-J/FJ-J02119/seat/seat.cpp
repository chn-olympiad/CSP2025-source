#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int s;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==s){
			if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2==0){
					cout<<1;
				}else{
					cout<<n;
				}
			}
			else{
				cout<<(i/n)+1<<" ";
				if((i-1)%n==0){
					if((i/n)%2==0){
						cout<<1;
					}else{
						cout<<n;
					}
				}else{
					cout<<(i%n)+1;
				}
			}
		}
	}
	return 0;
}
