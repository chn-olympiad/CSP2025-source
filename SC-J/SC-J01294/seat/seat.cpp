#include <bits/stdc++.h>
using namespace std;
int a[101],n,m,maxn,p[101],seati,mi,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int a1=a[1];
	for(int i=2;i>=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==a1){
			seati=cnt;
			break;
		}
	}
	int y=seati%n;
	if(y>0) mi=seati/n+1;
	else mi=seati/n;
	if(mi%2==0){
		if(y==0) cout<<mi<<" "<<1;
		else cout<<mi<<" "<<n-y+1;
	}
	else{
		if(y==0) cout<<mi<<" "<<n;
		else cout<<mi<<" "<<y;
	}
	return 0;
} 
