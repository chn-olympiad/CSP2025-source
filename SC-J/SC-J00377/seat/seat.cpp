#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int ax[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ax[i];
	}
	cnt=ax[1];
	sort(ax+1,ax+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(ax[i]==cnt){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if((cnt/n)%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<cnt/n+1<<" ";
		int y=cnt%n;
		if((cnt/n+1)%2==0){
			cout<<n-y+1;
		}else{
			cout<<y;
		}
	}
	return 0;
}