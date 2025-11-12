#include<bits/stdc++.h>
using namespace std;
struct ac{
	int num,cnt;
}a[1010];
bool cmp(ac x,ac y){
	return x.num<y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int ak=n*m;
	for(int i=1;i<=ak;i++){
		cin>>a[i].num;
		a[i].cnt=i;
	}
	sort(a+1,a+ak+1,cmp);
	int hang=1,lie=1;
	int rp=0;
	while(ak){
		int ff=true;
		if(a[ak].cnt==1){
			cout<<lie<<" "<<hang;
		}
//		cout<<hang<<" "<<lie<<endl;
		if(lie%2==1){
			if(hang==n){
				lie++;
				ff=false;
			}
		}else{
			if(hang==1){
				lie++;
				ff=false;
			}	
		}
		if(ff){
			if(lie%2==1){
				hang++;
			}else{
				hang--;
			}	
		}
		ak--;
		rp++;
	}
	return 0;
}//9:44 end ac?
