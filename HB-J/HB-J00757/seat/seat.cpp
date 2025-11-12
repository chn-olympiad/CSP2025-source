#include <bits/stdc++.h>
using namespace std;
int n,m,score,pos;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	score=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			pos=i;
			break;
		}
	}
	if(pos%n==0){
		if((pos/n)%2==1){
			cout<<pos/n<<" "<<n;
			return 0;
		}
		else{
			cout<<pos/n<<" "<<1;
			return 0;
		}
	}
	else{
		if(((pos-pos%n)/n)%2==0){
			cout<<(pos-pos%n)/n+1<<" "<<pos%n;
			return 0;
		}
		else{
			cout<<(pos-pos%n)/n+1<<" "<<n-pos%n+1;
			return 0;
		}
	}
	return 0;
}
