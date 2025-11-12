#include<bits\stdc++.h> 
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[1005];
int n,m,i=1,j=1,temp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	temp=a[1];
	sort(a+1,a+1+n*m,cmp);
	int o=1;
	if(temp==a[1]){
		cout<<1<<' '<<1;
		return 0; 
	}
	for(int k=2;k<=n*m;k++){
		if(j==m&&o==1){i++;o=-1;}
		else if(o==1)j++;		
		else if(j==1&&o==-1){i++;o=1;}
		else if(o==-1)j--;
		if(a[k]==temp)break;
	}
	cout<<i<<' '<<j<<endl;
	return 0;
} 
