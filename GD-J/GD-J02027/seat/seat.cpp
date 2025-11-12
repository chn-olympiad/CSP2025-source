#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int c=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c++;
	}
	int aa=a[1];
	sort(a+1,a+1+c,greater<int>());
	int sh;
	for(int i=1;i<=c;i++){
		if(a[i]==aa){
			sh=i;
			break; 
		}
	}
	int r;
	if(sh%n==0){
		r=sh/n;
		cout<<r<<' ';
	}else{
		r=(sh/n)+1;
		cout<<r<<' ';
	}
	if(r%2==1){
		cout<<sh%m;
	}else{
		cout<<1+m-(sh%m);
	}
	return 0;
}
