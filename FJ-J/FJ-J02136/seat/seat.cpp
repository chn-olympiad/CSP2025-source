#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	long long cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]){
			cnt++;
		}
	}
	if(cnt<=n){
		cout<<"1"<<" "<<cnt<<endl;
		return 0;
	}
	int cntt;
	cntt=cnt/n;	
	if(cntt%2==0){
		cout<<cntt+1<<" "<<abs(cnt-(cntt*n)); 
	
	}else {		
		cout<<cntt+1<<" "<<n-abs(cnt-(cntt*n))+1;
	} 
	
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
