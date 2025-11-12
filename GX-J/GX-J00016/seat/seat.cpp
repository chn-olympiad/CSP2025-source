#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[200],n,m,ren,win,R;
	cin>>n>>m;
	ren=n*m;
	cin>>a[1];
	R=a[1];
	for(int i=2;i<=ren;i++)cin>>a[i];
	sort(a+1,a+ren+1,cmp);
	for(int i=1;i<=ren;i++)
		if(a[i]==R)
			win=i;
	if(win==1)cout<<"1 1";
	else if(win%n==0){
		if((win/n)%2==1)cout<<win/n<<" "<<n;
		else cout<<win/n<<" 1";
	}
	else{
		if(((win/n)+1)%2==1)cout<<(win/n)+1<<" "<<win-((win/n)*n);
		else cout<<(win/n)+1<<" "<<(n-(win-((win/n)*n)))+1;
	}
	return 0;
}
