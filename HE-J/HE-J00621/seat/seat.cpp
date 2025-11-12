#include<bits/stdc++.h>
using namespace std;

int n,m,f,h=1,l=1;
const int N=1e3+5;
int a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) f++;
	}
	while(f--){
		if(l%2==1){
			h++;
			if(h>n){
				h=n;
				l++;
			}
		}
		else{
			h--;
			if(h<1){
				h=1;
				l++;
			}
		}
	}
	cout<<l<<" "<<h;
	
	return 0;
}
