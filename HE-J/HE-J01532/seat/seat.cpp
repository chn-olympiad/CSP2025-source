#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c=0,r=0;
	cin >> n >>  m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	if(n==1&&m==1){
		cout << 1 <<" "<< 1;
		return 0;
	}
	int num=n*m,x=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		if(a[i]==x){
			cnt=num-i+1;
			break;
		}
	}
	if(cnt<=m){
		cout << 1<<" "<<cnt;
	}else{
		r=cnt/m+1;//r为列，c为行 
		if(r%2==0){
			c=m-(cnt-(r-1)*m)+1;
		}else{
			c=cnt-(r-1)*m;
		}
		cout << r <<" "<<c;
	}
	return 0;
} 
