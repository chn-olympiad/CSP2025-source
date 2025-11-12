#include<bits/stdc++.h>
using namespace std;
int n,m,chen,a[100000],w,nm,wn,wm;
int eggsb(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++) cin>>a[i];
	chen=a[1];
	sort(a+1,a+1+nm,eggsb);
	
	for(int i=1;i<=nm;i++) if(a[i]==chen) {w=i;break;}
	for(int i=1;i<=m;i++){
		if(w>=n*(i-1)+1&&w<=i*n) {wn=i;break;}
	}
	 if(w%n==0) wm=n;
	  else wm=w%n;
	  if(wn%2==0) wm=n+1-wm;
	  cout<<wn<<" "<<wm; 
	return 0;
}

