#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct info{
	int x,y;
};
int a[100010],n,k,maxn=-2147483648,cnt1=0,cnt2=0;
info b[100010];
int yh(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++) sum^=a[i];
	return sum;
}
bool qj(int l1,int r1,int l2,int r2){
	if(l1>=l2&&r1<=r2) return false;
	if(l2>=l1&&r2<=r1) return false;
	if(r1>=l2&&r1<=r2) return false;
	if(l1>=l2&&l1<=r2) return false;
	if(r2>=l1&&r2<=r1) return false;
	if(l2>=l1&&l2<=r1) return false;
	return true;
}
bool pd(info c){
	for(int i=1;i<=cnt2;i++){
		if(!qj(b[i].x,b[i].y,c.x,c.y)) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(yh(i,j)==k&&pd({i,j})){
				cnt1++;
				b[cnt2].x=i;
				b[cnt2].y=j;
				cnt2++;
			}
		}
	}
	cout<<cnt1;
	return 0;
}
