#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int n,m,tmp,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			tmp=i;
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				sum++;
				if(sum==tmp){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				sum++;
				if(sum==tmp){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
