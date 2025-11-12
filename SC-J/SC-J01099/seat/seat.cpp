#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 1e3+50;
using namespace std;
int n,m,flag,x,y;
int a[N]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	flag=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			flag=i;
			break;
		}
	}
	if(flag%n==0){
		y=(flag/n)-1;
	}
	else{
		y=flag/n;
	}
	y++;
	if(y&1){
		x=flag%n;
		if(x==0) x=n;
	}
	else{
		x=n-(flag%n)+1;
		if(flag%n==0) x=1;
	}
	cout <<y <<" " <<x <<endl;
	return 0;
}
