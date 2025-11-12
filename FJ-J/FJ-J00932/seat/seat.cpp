#include<bits/stdc++.h>
using namespace std;

int n,m,cnt=1,tv;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>tv;
	for(int i=1;i<n*m;i++){
		int t;
		cin>>t;
		if(t>tv)cnt++;
	}
	int x=(cnt-1)/n;
	int y=(cnt-1)%n;
	if(x & 1){
		y=n-y-1;
	}
	cout<<x+1<<" "<<y+1<<endl;
	return 0;
}
