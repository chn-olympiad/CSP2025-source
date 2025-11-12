#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,x;
}a[105];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,tmp=1,sum=1,f=0;
	while(a[tmp].id!=1){
		if(i==n&&sum%2){
			j++;
			f=1;
			sum++;
			tmp++;
			continue;
		}
		if(i==1&&sum%2==0){
			sum++;
			f=0;
			j++;
			tmp++;
			continue;
		}
		tmp++;
		if(!f){
			i++;
		}else{
			i--;
		}
	}
	cout<<j<<' '<<i;
	return 0;
}
