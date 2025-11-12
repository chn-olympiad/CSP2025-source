#include<bits/stdc++.h>
using namespace std;
int s[105][105],l[105],score,lnidx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>l[i];
		if(i==0)score=l[i];
	}
	sort(l,l+x*y);
	for(int j=y;j>=1;j--){
		if(j%2==0){
			for(int i=1;i<=x;i++){
				s[i][j]=l[lnidx++];
				if(s[i][j]==score){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=x;i>=1;i--){
				s[i][j]=l[lnidx++];
				if(s[i][j]==score){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 
