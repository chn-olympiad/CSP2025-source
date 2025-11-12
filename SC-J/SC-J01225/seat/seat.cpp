#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1005*1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(long long)(n*m);i++){
		cin>>num[i];
	}
	int k=num[0];
	sort(num,num+(long long)(n*m),cmp);
	int idx=0;
	for(int i=0;i<(long long)(n*m);i++){
		if(num[i]==k){
			idx=i+1;
		}
	}
	int r=0,c=0;
	c=ceil(1.0*idx/n);
	if(c%2==0){
		int tmp=c*n;
		int dis=tmp-idx;
		r=1+dis;
	}else{
		int tmp=c*n;
		int dis=tmp-idx;
		r=n-dis;
	}
	cout<<c<<" "<<r;
	return 0;
}