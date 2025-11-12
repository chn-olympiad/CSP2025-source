#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,cntt;
struct GR{
	int gr,id;
}a[100005];
bool cmp(GR x,GR y){
	return x.gr>y.gr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt].gr;
			a[cnt].id=cnt;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				cntt++;
				if(a[cntt].id==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				cntt++;
				if(a[cntt].id==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}