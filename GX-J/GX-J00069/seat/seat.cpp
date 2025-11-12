#include<bits/stdc++.h>
using namespace std;
int n,m,as,a[1005],t,r;//as:所有的学生（AllStudent）

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	as=n*m;
	for(int i=1;i<=as;i++){
		cin>>a[i];
		r=a[1];
	}
	cout<<n<<" "<<m;
	return 0;
}
