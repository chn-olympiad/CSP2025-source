#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,m,cnt;
struct st{
	int ii,z;
}a[N];
bool cmp(st a,st b){
	return a.z>b.z;
}
int main(){
//	freopen("seat3.in","r",stdin);
//	freopen("seat3.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].z;
		a[i].ii=i;
	}
	sort(a+1,a+1+n*m,cmp);
//	//
//	for(int i=1;i<=n*m;i++)cout<<a[i].ii<<" ";
//	cout<<"\n";
//	//
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			++cnt;
			if(a[cnt].ii==1){
			int cp=j%n;
				if(i%2==1){
					if(cp==0){
						cout<<i<<" "<<n;
						return 0;
					}
					else{
						cout<<i<<" "<<cp;
						return 0;
					}
				}
				else{
					if(cp==0){
						cout<<i<<" "<<1;
						return 0;
					}
					else{
						cout<<i<<" "<<n-cp+1;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}

