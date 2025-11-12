#include<bits/stdc++.h>
using namespace std;
struct zuowei{
	int fs;
	int xh;
}a[20000];
bool cmp(zuowei w,zuowei q){
	if(w.fs>q.fs)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].xh=i;
	}
	int cnt=0;
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>0;j--){
				if(j<=0){
					break;
				}
				cnt++;
				if(a[cnt].xh==1){
				cout<<i<<' '<<j;
				return 0;	
				}
			}
		}else{
			for(int j=1;i<=n;j++){
				if(j>n){
					break;
				}
				cnt++;
				if(a[cnt].xh==1){
				cout<<i<<' '<<j;
				return 0;	
				}
			}
		}
	}
	return 0;
}
