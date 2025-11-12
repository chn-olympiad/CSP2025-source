#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e2+10;

ll n,m,cx=1,cy=1,book,l;
ll a[105];

bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(ll i=1;i<=l;i++){
		cin>>a[i];
	}
	book=a[1];
	sort(a+1,a+l+1,cmp);
	for(ll i=1;i<=l;i++){
		if(a[i]==book){
			cout<<cy<<" "<<cx;
			return 0;
		}
		if(cy%2==0){
			if(cx==1&&cy<m){
				cy++;	
			}else if(cx>1){
				cx--;
			}
		}else if(cy%2==1){
			if(cx==n&&cy<m){
				cy++;	
			}else if(cx<n){
				cx++;
			}
		}
	}
	/*
	3 3
	94 95 96 97 98 99 100 93 92
	*/
	return 0;
}

