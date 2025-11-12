#include<bits/stdc++.h>
using namespace std;
int n,m;
int num;
int a[20][20];
int grade[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	num=n*m;
	int x=1,y=1;
	for(int i=1;i<=num;i++)cin>>grade[i];
	int r=grade[1];
	int cnt;
	sort(grade+1,grade+num+1,greater<int>());
	for(int i=1;i<=num;i++){
		if(grade[i]==r){
			cnt=i;
			break;
		}
	}
	if(cnt<=n){
		cout<<1<<" "<<cnt;
		return 0;
	}
	if(cnt%n!=0)y=cnt/n+1;
	else y=cnt/n;
	if(y%2!=0){
		if(cnt%n==0)x=n;
		else x=cnt%n;
	}
	else{
		if(cnt%n==0)x=1;
		else x=n+1-cnt%n;
	}
	cout<<y<<" "<<x;
	return 0;
}