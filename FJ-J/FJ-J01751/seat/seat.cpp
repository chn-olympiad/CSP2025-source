#include <bits/stdc++.h>
using namespace std;
int a[1000000];
bool cmp(int a,int b){
	return a>b;
}		
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[num];
			num++;
		}
	}
	s=a[1];
	sort(a+1,a+1+num,cmp);
	num=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[num]==s){
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		}else{
			for(int j=n;1<=j;j--){
				if(a[num]==s){
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		}
	}
}				
