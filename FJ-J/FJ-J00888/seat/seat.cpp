#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
bool com(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tot=a[1],st;
	sort(a+1,a+1+n*m,com);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tot){
			st=i-1;
			break;
		}
	}
	int k=st%n+1,p=st/n+1;
	//cout<<k<<' '<<p<<' '<<st<<'\n';
	if(p%2==0){
		cout<< p<<' '<<n-k+1;
	}else {
		cout<<p<<' '<<k;
	}
	return 0;
}
