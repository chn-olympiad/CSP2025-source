#include<bits/stdc++.h>
using namespace std;
int num[30][30],n,m,nim[900];
bool cmp(int a,int b){return a>b;}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int a=0;a<m;a++){
		if(a%2==0){
			for(int b=0;b<n;b++){
				num[b][a]=a*n+b;
			}
		}
		else{
			for(int b=0;b<n;b++){
				num[n-b-1][a]=a*n+b;
			}
		}
	}
	int sl=n*m;
	for(int a=0; a<sl; a++) {
		cin>>nim[a];
	}
	int R=nim[0],pm;
	sort(nim,nim+sl,cmp);
	for(int a=0;a<sl;a++){
		if(nim[a]==R) {
			pm=a;
			break;
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(num[a][b]==pm){
				cout<<b+1<<" "<<a+1;
				return 0;
			}
		}
	}
	return 0;
}
