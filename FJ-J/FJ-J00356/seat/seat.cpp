#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a*b];
	for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	int d=c[0];
	sort(c,c+a*b);
	for(int i=0;i<a*b/2;i++)swap(c[i],c[a*b-1-i]);
	for(int i=0;i<b;i++){
		for(int y=0;y<a;y++){
			if(c[i*a+y]==d){
				cout<<i+1<<" ";
				if(i%2==0)cout<<y+1;
				else cout<<a-y;
				return 0;
			}
		}
	}
} 
