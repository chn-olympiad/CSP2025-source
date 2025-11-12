#include<bits/stdc++.h>
using namespace std;
int jml[10086];
int main(){
	freopen("seat3.in","r",stdin);
	freopen("ans2.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int n,m,jml1,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){cin>>jml[i];}
	jml1=jml[1];
	sort(jml+1,jml+n*m+1);
	num=n*m;
	for(int i=1;i<=m;i++){
		if((i%2)==1){
			for(int j=1;j<=n;j++){
				if(jml[num]==jml1){
					cout<<i<<' '<<j;
					return 0;
				}
				num--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(jml[num]==jml1){
					cout<<i<<' '<<j;
					return 0;
				}
				num--;
			}
		}
	}
}