#include<bits/stdc++.h>

using namespace std;
int seat[15][15];
int n,m;
struct test{
	int num;
	int id;
}a[110];
bool cmp(test x,test y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+k+1,cmp);
	int cnt;
	for(int i=1;i<=k;i++){
		if(a[i].id==1){
			cnt=i;
			break;
		}
	}
	int js=0;
	int c,r;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				js++;
				if(js==cnt){
					c=j;r=i;
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
		if(j%2==0){
			for(int i=n;i>=1;i--){
				js++;
				if(js==cnt){
					c=j;r=i;
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
}

