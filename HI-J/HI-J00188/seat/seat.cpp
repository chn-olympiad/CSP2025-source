#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1);
	int c=1,r=1,i=n*m,willdo=0;
	for (;;i--){
		if (a[i]==s) break;
		if (willdo==0){
			if (r>=n) c++,willdo=1;
			else r++;
		}else{
			if (r<=1) c++,willdo=0;
			else r--;
		}
	}
	cout<<c<<' '<<r;
	return 0; 
}
