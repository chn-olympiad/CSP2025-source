#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f[10010]={},score,num=1;
	cin>>n>>m;		//n–– m¡– 
	for(int i=1;i<=n*m;i++)
		scanf("%d",&f[i]);
	score=f[1];
	sort(f+1,f+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<f[i]<<" ";
		if(f[i]==score){
			num=i;
			break;
		}
	}
	int c=ceil(1.0*num/n),r;
	num=num-(c-1)*n;
	if(c%2){
		r=num;
	}
	else{
		r=n-(num-1);
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
