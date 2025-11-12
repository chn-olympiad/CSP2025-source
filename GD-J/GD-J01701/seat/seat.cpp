#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[120];
int n,m;
int cnt=1;
bool num;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if(a[i]>a[1]) cnt++;
	}
	int h,l;
	h=l=1;
	for(int i=1;i<cnt;i++){
		if(num){//Å¼Êý
			h--;
			if(h<1){
				l++;
				h=1;
				num=false;
				}
			}
			else{//ÆæÊý 
				h++;
				if(h>m){
					h=m;
					l++;
					num=true;
				}
			} 
	}
	printf("%lld %lld",l,h);
}
