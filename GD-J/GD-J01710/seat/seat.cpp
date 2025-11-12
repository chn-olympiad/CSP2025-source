#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			cnt++;
		} 
	}
	long long x=cnt/m;
	long long y=0;
	if(cnt%m==0){
		if(x%2==1){
			y=m;
		}else{
			y=1;
		}
	}else{
		x++;
		if(x%2!=0){
			y=cnt%m;
		}else{
			y=m-(cnt%m)+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
