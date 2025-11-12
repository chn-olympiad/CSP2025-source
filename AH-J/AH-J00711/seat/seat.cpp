#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int x=n*m;
    int a[x];
    int b=0;
    int f=0;
    int y;
    for(int i=0;i<x;i++){
		cin>>a[i];
		}	
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		for(int i=0;i<x;i++){
		if(a[0]<a[i]){b++;}
		}
		if(b%n==0){
			 y=b/n;
			if(y%2==0){f++;}
		}
		else{
			int y=b/n+1;
			if(y%2==0)
			{
				f++;
			}
			}
			if(f%2==1){
			cout<<y+1<<" ";
				cout<<f%n<<" ";
			}
			else{
			cout<<y+1<<" ";
			cout<<n-f%n<<" ";
				}
	return 0;
	}
