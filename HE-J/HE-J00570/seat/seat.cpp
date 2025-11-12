#include<bits/stdc++.h>
using namespace std;
bool px(int a,int b){
	return a>b;
}
int main(){
	int n,m,o=0,d;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=n*m;
	int b[a-1];
	cin>>d;
	for(int i=0;i<a-1;i++){
		cin>>b[i];
	}
	sort(b,b+a-1,px);
	for(int j=0;j<m/2;j++){
		for(int i=1;i<=n;i++){
			if(d>b[o]){
				cout<<j*2+1<<" "<<i;
				return 0;
			}
		o++;	
		}
		for(int i=n;i>=1;i--){
			if(d>b[o]){
				cout<<j*2+2<<" "<<i;
				return 0;
			}
		o++;	
		}
	}
	if(m%2!=0){
		for(int i=1;i<=n;i++){
			if(d>b[o]){
				cout<<m<<" "<<i;
				return 0;
			}
		o++;	
		}
	}
	cout<<m<<" "<<n;
	return 0;
} 
