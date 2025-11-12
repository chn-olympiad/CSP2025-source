#include<bits/stdc++.h>
using namespace std;
int n,m;
int sc[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	int rsc=sc[1];
	sort(sc+1,sc+1+n*m,cmp);
	int cnt=1;
	for(int lie=1;lie<=m;lie++){
		if(lie%2==0){
			for(int hang=n;hang>=1;hang--){
				if(sc[cnt++]==rsc){
					cout<<lie<<" "<<hang;
					return 0;
				}
			}
		}else{
			for(int hang=1;hang<=n;hang++){
				if(sc[cnt++]==rsc){
					cout<<lie<<" "<<hang;
					return 0;
				}
			}
		}
	}
	return 0;
}
