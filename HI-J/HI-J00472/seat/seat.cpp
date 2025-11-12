#include<bits/stdc++.h>
using namespace std;
int l,r,u,ui,arr[10005];
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>l>>r;
	for(int i=1;i<=l*r;i++){
		cin>>arr[i];
	}
	u=arr[1];
	sort(arr+1,arr+(l*r)+1,cmp);
	for(int i=1;i<=l*r;i++){
		if(arr[i]==u){
			ui=i;
			break;
		}
	}
	int w=ui/l;
	cout<<ui/l<<' ';
	if(ui==l*w){
		if((ui/l)%2==0){
			cout<<1;
		}
		else{
			cout<<l;
		}
	}
	else{
		if((ui/l+1)%2==0){
			cout<<l-ui%l+1;
		}
		else{
			cout<<ui%l;
		}
	}
	return 0;
}
