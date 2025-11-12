#include<bits/stdc++.h>
using namespace std;
struct N{
	int val;
	bool is;
};
bool cmp(N x,N y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	N lst1[1000]{};
	cin>>lst1[0].val;
	lst1[0].is=1;
	for(int i=1;i<n*m;i++){
		scanf("%d",&lst1[i].val);
	}
	sort(lst1,lst1+n*m,cmp);
	int nn;
	for(int i=0;i<m*n;i++){
		if(lst1[i].is==1){
			nn=i+1;
			break;
		}
	}
	int col=ceil(1.0*nn/n);
	if(col%2==1){
		cout<<col<<" "<<nn-(col-1)*n;
	}else{
		cout<<col<<" "<<(n-(nn-(col-1)*n)+1);
	}
	return 0;
} 