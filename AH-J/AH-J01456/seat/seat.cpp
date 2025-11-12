#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],p,pos;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			pos=i;
			break;
		}
	}
	if(n==1){
		cout<<pos<<" "<<1;
	}else if(m==1){
		cout<<1<<" "<<pos;
	}else if(m==2){
		if(pos<=n)	cout<<"1 "<<pos;
		else{
			cout<<"2 "<<n*m-pos+1;
		}
	}else if(n==2){
		int mod=pos%4,sh=pos/4*2;
		if(mod==0)	cout<<sh<<" 1";
		else if(mod==1)	cout<<sh+1<<" 1";
		else if(mod==2) cout<<sh+1<<" 2";
		else	cout<<sh+2<<"2";
	}
	return 0;
}
