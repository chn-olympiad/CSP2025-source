#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=1,h=0,max=-1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>max){
			max=a;
			h++;
			if(h>m){
				l++;
			}
		}
		cout<<l<<" "<<h<<" ";
	}
	
	return 0;
}
