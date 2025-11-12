#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int a[s];
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	int a1=a[0];
	int x=1,y=1;
	int pm=0;
	sort(a,a+s);
	for(int i=0;i<s;i++){
		if(a[i]==a1){
			pm=s-i;
		}
	}
	//   94 95 96 97 98 99 100 93 92
	for(int i=0;i<m;i++){
		if(pm>n){
			pm-=n;
			x++;
		}else{
			if(x%2==0){
				y=n+1-pm;
			}else{
				y=pm;
			}
			break;
		}
		
	}
	cout<<x<<' '<<y;
	
	return 0;
}
