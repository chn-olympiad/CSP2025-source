#include<bits/stdc++.h>
using namespace std;
long long a[105],b[12][12];
bool cmp(int abcd,int abce){
	return abcd>abce;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[1];
	sort(a+1,a+n*m+1,cmp);
	int xb=1,kaishi=0,jieshu=n,sbb=1;
	for(int i=1;i<=m;i++){
		for(int j=kaishi;j!=jieshu;j+=sbb){
			b[i][j]=a[xb++];
			if(b[i][j]==xiaor){
				cout<<i<<' ';
				if(sbb==1){
					cout<<j+1;
				}else{
					cout<<j;
				}
				break;
			}
		}
		swap(kaishi,jieshu);
		if(i%2==1){
			sbb=-1;
		}else{
			sbb=1;
		}
	}
	return 0;
}
