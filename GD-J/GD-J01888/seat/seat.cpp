#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cnt,news,num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
		}
	}
	num=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==num){
			news=i;
			break;
		} 
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(++cnt==news){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(++cnt==news){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
