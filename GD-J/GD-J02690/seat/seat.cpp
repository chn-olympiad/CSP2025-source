#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,num,p;
struct node{
	int id,point;
}a[10005];
bool cmp(node x,node y){
	return x.point>y.point;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i].point;
		a[i].id=i;
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i].id==1){
			p=i;
			break;
		}
	}
	int now=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			now++;
			if(now==p){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
		i++;
		if(i>m){
			return 0;
		}
		for(int j=n;j>=1;j--){
			now++;
			if(now==p){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}











