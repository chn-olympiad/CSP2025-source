#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],r,pos,now;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==r) {
			pos=i;
			break;
		}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				now++;
				if(now==pos){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				now++;
				if(now==pos){
					cout<<m<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
