#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=0;i<p;i++){
		cin>>a[i];
	}
	int q=a[0];
	sort(a,a+p,cmp);
	int cnt=0;
	for(int i=0;i<p;i++){
//		cout<<a[i]<<' '; 
		if(a[i]==q){
			cnt=i+1;
			break;
		}
	}
//	cout<<cnt<<endl;
	int ans1=(cnt-1)/n+1,ans2=0;
	if(ans1%2){
		ans2=ans1%n+1;
	}
	else{
		ans2=n-ans1%n;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
