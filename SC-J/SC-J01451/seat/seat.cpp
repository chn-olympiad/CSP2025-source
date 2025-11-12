#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
int n,m,top;
struct f{
	int i,v;
}a[505];
bool cmp(f q,f p){
	return q.v>p.v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				++top;
				if(a[top].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else {
			for(int j=m;j>=1;j--){
				++top;
				if(a[top].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		
	}
	return 0;
}