#include<bits/stdc++.h>
using namespace std;
int n,m;
int L;
int Lid;
int pos[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>pos[i];
//		cout<<pos[i]<<" ";
	}
	L=pos[1];
//	cout<<L;
	sort(pos+1,pos+len+1,cmp);
	for(int i=1;i<=len;i++){
//		cout<<pos[i]<<" ";
		if(pos[i]==L){
			Lid=i;
			break;
		}
	}
//	cout<<Lid;
	int x=ceil(Lid/n)+1;
	if(Lid<=n){
		cout<<1<<" "<<Lid;
	}else if(x%2==0){
		cout<<x<<" "<<x*n-Lid+1;
	}else if(x%2==1){
		cout<<x<<" "<<Lid-(x-1)*n;
	}
	return 0;
}
