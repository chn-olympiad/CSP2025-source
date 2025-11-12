#include<bits/stdc++.h>
using namespace std;
struct student{
	long long score,id;
}a[225];
long long n,m;
bool cmp(student x, student y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].score;
	}
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%n!=0){
				if(i%n!=1)cout<<i/n+(i%n)/2<<" "<<i%n+1;
				else if(i<n||i%2*n==1)cout<<i%n+i/n<<" "<<"1";
				else cout<<i%n+i/n<<" "<<i%n+1;
			}
			else if(i==n)cout<<i/n<<" "<<"2";
			else cout<<i/n<<" "<<"1";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
