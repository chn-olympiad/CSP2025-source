#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const bool ts=false;
struct ter{
	int v;
	int i;
}a[103];
int b[11][11];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if(!ts){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
	}
	//freopen("","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].v;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,[](ter a,ter b){return a.v>b.v;
	});
	int cur=1,i=1,j=1;
	while(cur<=n*m){
		b[i][j]=a[cur++].i;
		if(b[i][j]==1){
			cout<<j<<" "<<i;
			return 0;
		}
		if(j%2)++i;
		else --i;
		if(i<1){
			i=1;++j;
		}
		if(i>n){
			i=n;++j;
		}
	}
} 