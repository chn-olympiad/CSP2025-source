#include<bits/stdc++.h>
#define qwq return
#define zzz long long
using namespace std;
zzz n,m,a[10000001],flg,ansx=1,ansy=1,cnt=0;
bool sor(zzz x,zzz y){
	qwq x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(zzz i=1;i<=n*m;i++)cin>>a[i];
	flg=a[1];
	sort(a+1,a+n*m+1,sor);
	for(zzz i=1;i<=n*m;i++){
		if(a[i]==flg){
			flg=i-1;
			break;
		}
	}
	while(flg){
		flg--;
		if(cnt==0){
			ansx++;
			if(ansx>n){
				ansy++;
				ansx--;
				cnt=1;
			}
		}
		else{
			ansx--;
			if(ansx<1){
				ansy++;
				ansx++;
				cnt=0;
			}
		}
	}
	cout<<ansy<<" "<<ansx;
	qwq 0;
}