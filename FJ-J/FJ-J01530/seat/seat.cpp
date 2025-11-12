#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[114],a_sc,num,x[101],y[101],xxx=1,yyy=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	x[1]=1;
	y[1]=1;
	for(int i=1;i<=100;i++){
		x[i]=xxx;
		if(xxx%2==1){
			y[i]=yyy;
			yyy++;
		}else{
			yyy--;
			y[i]=yyy;
		}
		if(i%n==0){
			xxx++;
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			a_sc=a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a_sc==a[i]){
			num=i;
			break;
		}
	}
	cout<<x[num]<<' '<<y[num];
	return 0;
}
