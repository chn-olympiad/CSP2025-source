#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],Ansx,Ansy,f;
bool cmp(int x,int y){
	return x>y;
}
void m11(int x,int y,bool X,int hao){
	if(f==a[hao]){
		Ansx=x;
		Ansy=y;//cout<<"mk:"<<hao<<" "<<x<<' '<<y<<' '<<"end"<<'\n';
		return;
	}
	else if(X==true&&x<n){//向下
		//cout<<"mk:"<<hao<<" "<<x<<' '<<y<<' '<<"down"<<'\n'; 
		m11(x+1,y,X,hao+1);
	}
	else if(X==true&&x==n){//下顶头向右 
	//cout<<"mk:"<<hao<<" "<<x<<' '<<y<<' '<<"turn down"<<'\n'; 
		m11(x,y+1,false,hao+1);
	}
	else if(X==false&&x>1){//向上 
	//cout<<"mk:"<<hao<<" "<<x<<' '<<y<<' '<<"up"<<'\n'; 
		m11(x-1,y,X,hao+1);
	}
	else if(X==false&&x==1){//上顶头向右 
	//cout<<"mk:"<<hao<<" "<<x<<' '<<y<<' '<<"turn up"<<'\n'; 
		m11(x,y+1,true,hao+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<" "<<a[i]<<' ';
//	}
	m11(1,1,true,1);
	cout<<Ansy<<" "<<Ansx;
	return 0;
}
