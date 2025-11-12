#include<bits/stdc++.h>
using namespace std;
long long int n,m;
struct seat{
	long long int score,s;
}a[10010];
bool cmp(seat x,seat y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long int seat1;
	for(long long int i=1;i<=n*m;i++){
		cin>>a[i].score;
		if(i==1) seat1=a[i].score;
	}
	sort(a+1,a+1+n*m,cmp);
	long long int id;
	for(long long int i=1;i<=n*m;i++){
		a[i].s=i;
		if(a[i].score==seat1) id=a[i].s;
	}
	if(id/n==0 || id==n){
		cout<<"1"<<" "<<id<<endl;
		return 0;
	}else if(id%n==0){
		if((id/n)%2==0){
			cout<<id/n<<" "<<"1"<<endl;
			return 0;
		}else{
			cout<<id/n<<" "<<n<<endl;
			return 0;
		}
	}else{
		if((id/n)%2==0){
			cout<<id/n+1<<" "<<id%n<<endl;
			return 0;
		}else{
			cout<<id/n+1<<" "<<n-id%n+1<<endl;
			return 0;
		}
	}
	return 0;
}
