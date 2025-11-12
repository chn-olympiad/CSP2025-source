#include<bits/stdc++.h>
using namespace std;
int cj[100005];
int n,m;//n行数 m列数 
int q,p;//q行数 p列数 
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int o=n*m;
	for(int i=1;i<=n*m;i++)cin>>cj[i];
	int flag=cj[1];
	int num;
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cj[i]==flag){
			num=i;
			break;
		} 
	}
	for(int i=0;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i*n+j==num){
				q=i,p=j;
				break;
			}
		}
	}
	if(q%2==0){
		cout<<q+1<<" "<<p;
	}
	else{
		cout<<q+1<<" "<<m-p+1;
	}
	return 0;
}