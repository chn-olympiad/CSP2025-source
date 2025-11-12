#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(r<a){
			cnt++;
		}
	}
	int h,l=cnt/n;
	if(cnt%n!=0){
		l++;
	}
	cnt%=n;
	if(l%2==0){
		h=n-cnt;
	}
	else{
		h=cnt+1;
	}
	cout<<l<<" "<<h;
	//Ç©µ½Ìâ*2
	//9:01
}
