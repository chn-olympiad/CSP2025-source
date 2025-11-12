#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],me,p=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	me=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[p]==me){
					cout<<i<<' '<<j;
					return 0;
				}
				p++;
			}
		}
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[p]==me){
					cout<<i<<' '<<j;
					return 0;
				}
				p++;
			}
		}
	}
	return 0;
} 
