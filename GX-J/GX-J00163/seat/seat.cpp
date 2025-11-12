#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],b[11][11],num=0;
bool cmp(int A,int B){
	return A>B;
}
stack<int >sta;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1)num=a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i){
		sta.push(a[i]);
	}
	for(int i=1;i<=m;++i){
		if(i%2!=0){
			for(int j=1;j<=n;++j){
				b[j][i]=sta.top();
				sta.pop();
			}			
		}
		else{
			for(int j=n;j>=1;--j){
				b[j][i]=sta.top();
				sta.pop();
			}
		}
	}
	for(int i=1;i<=10;++i){
		for(int j=1;j<=10;++j){
			if(b[j][i]==num){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
