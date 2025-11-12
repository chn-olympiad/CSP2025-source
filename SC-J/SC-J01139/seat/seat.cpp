#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m;
	int zyx;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	zyx=a[1];
	sort(a+1,a+1+cnt,cmp);
	int now=1,sum=0;
	for(int i=1;i<=m;i++){
		if(now==1){
			for(int j=1;j<=n;j++){
				sum++;
				if(a[sum]==zyx){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
			now=2;
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(a[sum]==zyx){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
			now=1;
		}
	}
	return 0;
}