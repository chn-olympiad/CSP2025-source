#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,cnt=1,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]){
			cnt++;
			//计算名次 
		}
	}
	y=ceil(1.0*cnt/n);
	//计算列数 
	cnt=(cnt-1)%n+1;
	//剩下的数量 
	if(y%2==0){
		x=n-cnt+1;
		//偶数列从下往上数 
	}else{
		x=cnt;
		//奇数列直接得出结果 
	}
	cout<<y<<" "<<x;
	//先列再行 
	return 0;
}
