#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
struct node{
	int da,xi;
};
bool cmp(node a,node b){
	return a.da>b.da;
}
node num[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=m;j++){
			cin>>num[i*m+j].da;
			num[i*m+j].xi=i*m+j;
		}
	}
	sort(num+1,num+1+(n*m),cmp);
	int x,y,no=1;
	for(int i = 0;i<n;i++){
		if((i+1)&1){
			for(int j = 1;j<=m;j++){
				if(num[no].xi==1){
					cout<<i+1<<" "<<j;
					return 0;
				}
				no++;
			}
		}else{
			for(int j = m;j>=1;j--){
				if(num[no].xi==1){
					cout<<i+1<<" "<<j;
					return 0;
				}
				no++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
