#include<bits/stdc++.h>
using namespace std;
int n,m,x,xm,flag;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			a.push_back(x);
		}
	}
	xm=a[0];
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++) {
		if(a[i]==xm){
			flag=i+1;
			break;
		}
	}
	if(flag%n==0){
		if((flag/n)%2==1) cout<<flag/n<<" "<<n;
		else cout<<flag/n<<" "<<1;
	}
	else {
		if((flag/n+1)%2==1) {
			cout<<flag/n+1<<" "<<flag%n;
		}
		else {
			cout<<flag/n+1<<" "<<(n-flag%n+1);
		}
	}
	return 0;
}