#include <bits/stdc++.h>
using namespace std;
int aaaa[110];
bool bj(int xdh,int ydh){
	return xdh>ydh;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int naaa,maaa,raaa;
	cin>>naaa>>maaa>>raaa;
	aaaa[0]=raaa;
	for(int iaaa=1;iaaa<maaa*naaa;iaaa++){
		cin>>aaaa[iaaa];
	}
	sort(aaaa,aaaa+maaa*naaa+1,bj);
	int taaa=1;
	for(int iaaa=1,jaaa=1,cntaaa=0;iaaa<=naaa && jaaa<=maaa;cntaaa++){
		if(aaaa[cntaaa]==raaa){
		cout<<jaaa<<" "<<iaaa;
		break;}
		iaaa+=taaa;
		if(iaaa>naaa){
			iaaa=naaa;
			taaa=-1;
			jaaa++;
		}
		if(iaaa<1){
			iaaa=1;
			taaa=1;
			jaaa++;
		}
	}
	return 0;
} 