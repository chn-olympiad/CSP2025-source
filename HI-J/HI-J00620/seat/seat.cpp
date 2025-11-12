#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	int c=n*m;
	int a[c];
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	int f=a[0];
	sort(a,a+c);
	int h=0;
	for(int i=0;i<c;i++){
		if(a[i]==f){
			h=h+(c-i);
			break;
		}
	} 
	int u=0;
	if(h>m){
		u=u+h/m;
	}
	cout<<u<<" "<<h/m;
//	int n,m;
//	cin>>n>>m;
//	int c=n*m;
	
	return 0;
}
