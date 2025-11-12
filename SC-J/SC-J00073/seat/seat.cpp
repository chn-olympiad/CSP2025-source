#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int fenshu;
};
bool my_cmp(node a,node b){
	return a.fenshu>b.fenshu;
}
node a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N*M;i++){
		a[i].id=i;
		cin>>a[i].fenshu;
	}
	sort(a+1,a+N*M+1,my_cmp);
	int p=0;
	for(int i=1;i<=M;i++){
		if(i%2==1){
			for(int j=1;j<=N;j++){
				p++;
				if(a[p].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=N;j>=1;j--){
				p++;
				if(a[p].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
//I love CCF very much