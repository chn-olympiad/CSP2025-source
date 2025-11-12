#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int x=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[n*m-i+1];
	}
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			id=i;
			break;
		}
	}
	int num=0;
	if(id%m==0){
		cout<<id/m<<" ";
		num=id/m;
	}
	else{
		cout<<id/m+1<<" ";
		num=id/m+1;
	}
	if(num%2==0){
		if(m-id%m+1==0){
			cout<<m;
		}
		else cout<<m-id%m+1;
	}
	else{
		if(id%m==0)cout<<m;
		else cout<<id%m;
	}
//	int cnt=0;
//	int i=1,j=0;
//	while(i<=n){
//		for(j=1;j<=m;j++){
//			cnt++;
//			if(cnt==id){
//				cout<<i<<" "<<j;
//				return 0;
//			}
//		}
//		j--;
//		i++;
//		cnt++;
//		if(cnt==id){
//			cout<<i<<" "<<j;
//			return 0;
//		}
//		for(int j=m;j>=1;j--){
//			cnt++;
//			if(cnt==id){
//				cout<<i<<" "<<j;
//				return 0;
//			}
//		}
//	}
	return 0;
}