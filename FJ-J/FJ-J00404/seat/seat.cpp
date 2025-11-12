#include<bits/stdc++.h>
using namespace std;
int l;
int arr[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w=0;
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>arr[i];
	}
	int g=arr[1];
	sort(arr+1,arr+1+l);
	for(int i=1;i<=l;i++){
		if(g==arr[i]){
			w=i;
			break;
		}
	}
	w=l-w;
	int l=w/n,h=w%n;
	int s=l%2;
	if(!s){
		cout<<l+1<<" "<<h+1;
	}if(s){
		cout<<l+1<<" "<<n-h;
	}
	return 0;
}
