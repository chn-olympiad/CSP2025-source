#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int a[105],n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;++i){
		cin>>a[i];
	}
	int b=a[1],cnt=0;
	sort(a+1,a+1+s);
	for(int i=s;i>=0;--i){
		++cnt;
		if(a[i]==b){
			break;
		}
	}
	int y=cnt%n,x=cnt/n;
	if(y!=0)++x;
	else y=n;
	if(x%2){
		cout<<x<<' '<<y;
	}else{
		cout<<x<<' '<<n-y+1;
	}
	return 0;
}