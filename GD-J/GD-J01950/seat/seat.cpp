#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e2+10;
int n,m;
struct mem{
	int sc,id;
}a[N*N];
bool cmp(mem a,mem b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for (int ml=1;ml<=m;ml++){
		if (ml%2==1){
			for (int nl=1;nl<=n;nl++){
				++cnt;
				if (a[cnt].id==1){
					cout<<ml<<" "<<nl<<endl;
					return 0;
				}
			}
		}else {
			for (int nl=n;nl>=1;nl--){
				++cnt;
				if (a[cnt].id==1){
					cout<<ml<<" "<<nl<<endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
