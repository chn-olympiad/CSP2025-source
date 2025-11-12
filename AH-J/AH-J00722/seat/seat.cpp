#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ming=0,mc=0;
bool cmp(int x,int y){
	return x>y;
}
void fang(int i,int j,int c,bool Y){
	if(Y==1){
		while(c<mc){
			if(i==1){
				return fang(1,j+1,c+1,0);
			}else{
				i--;
				c++;
			}
		}
		cout<<j<<" "<<i;
	}else{
		while(c<mc){
			if(i==n){
				return fang(n,j+1,c+1,1);
			}else{
				i++;
				c++;
			}
		}
		cout<<j<<" "<<i;
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		ming=a[1];
	}
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=b;i++){
		if(a[i]==ming){
			mc=i;
			break;
		}
	}
	fang(1,1,1,0);
	return 0;
}
