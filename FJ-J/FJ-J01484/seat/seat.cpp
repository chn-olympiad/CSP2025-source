#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int v,idx;//成绩和下标 
}a[200];

bool cmp(Node x,Node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].idx=i;
	}
	
	sort(a+1,a+n*m+1,cmp);
	int k=0;//计数表示当前排到第几个 
	for(int j=1;j<=m;j++){//模拟 
		if(j%2==1){
			//奇数列：行从小到大
			for(int i=1;i<=n;i++){
				if(a[++k].idx==1){
					//到了小R
					cout<<j<<" "<<i;
					break; 
				}
			}
		}else{
			//偶数列：行从大到小 
			for(int i=n;i>=1;i--){
				if(a[++k].idx==1){
					//到了小R
					//cout<<a[k].v<<" ";
					cout<<j<<" "<<i;
					break; 
				}
			}
		}
		
	}
	return 0;
}
