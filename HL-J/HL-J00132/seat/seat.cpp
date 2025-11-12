#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],nm,cnt=0;
	cin>>n>>m;
	nm=n*m;
	int r=a[0];
	sort(a,a+nm,cmp);
	for(int i=0;i<nm;i++){
		cout<<a[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
