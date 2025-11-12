#include<bits/stdc++.h>
using namespace std;
int n,m;
int mm;
int sum=1;
int h=1,l=1;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m>>mm;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>=mm)sum++;
	}
	for(int i=1;i<sum;i++){
		if(l%2){
			if(h+1<=m)h++;
			else l++;
		}else{
			if(h-1>=1)h--;
			else l++;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
