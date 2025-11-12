#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m,a[505];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+n*m+1);
	int x=1;
	for(;x<=n*m;x++){
		if(a[n*m-x+1]==z)break;
	}
	int o=n*2;
	int h=x/o;
	h*=2;
	int w=x%o;
	if(w>0)h++;
	if(w>n){
		h++;
		w=2*n-w+1;
	}
	cout<<h<<" "<<w;
	return 0;
}
