#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1009],cnt=0;
int xr;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int lie=1;lie<=m;++lie){
		if(lie&1){
			for(int hang=1;hang<=n;++hang){
				int num=a[++cnt];
				if(num==xr){
					cout<<lie<<' '<<hang<<'\n';
					return 0;
				}
			}
		}else{
			for(int hang=n;hang>=1;--hang){
				int num=a[++cnt];
				if(num==xr){
					cout<<lie<<' '<<hang<<'\n';
					return 0;
				}
			}
		}
		
	}
	return 0;
}
