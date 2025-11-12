#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n*m;
	int q[a];
	for(int i=0;i<a;i++){
		cin>>q[i];
	}
	int qwq=q[0],qw=0,we=0;
	int cnt=0;
	sort(q,q+a,cmp);
	bool f=1;
	for(int i=1;i<=m;i++){
		if(f==1){
			if(i%2!=0){
				for(int j=1;j<=n;j++){
					if(qwq==q[cnt]){
						qw=i;
						we=j;
						f=0;
						break;
					}
					cnt++;
				}	
			}else{
				for(int j=n;j>0;j--){
					if(qwq==q[cnt]){
						qw=i;
						we=j;
						f=0;
						break;
					}
					cnt++;
				}
			}
		}
	}
	cout<<qw<<' '<<we;
	return 0;
}
