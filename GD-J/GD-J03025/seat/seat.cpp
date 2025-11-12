#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[110];
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
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int X=1,Y=1;
	bool Flag=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<Y<<' '<<X;
			return 0;
		}else{
			if((X==n&&Flag)||(X==1&&!Flag)){
				Y++;
				if(Flag){
					Flag=0;
				}else{
					Flag=1;
				}
			}else if(Flag){
				X++;
			}else if(!Flag){
				X--;
			}
		}
	}
	return 0;
} 
