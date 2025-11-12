#include<bits/stdc++.h>
using namespace std;
struct stu{
	int store;
	int id;
};
bool cmp(stu a,stu b){
	return a.store<b.store;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0;
	stu a[100001];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].store;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				t++;
				if(a[t].id==1)cout<<i<<" "<<j;
				return 0;
			}
		}else {
			for(int j=1;j<=n;j++){
				t++;
				if(a[t].id==1)cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

