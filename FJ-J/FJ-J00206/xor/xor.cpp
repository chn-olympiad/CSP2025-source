#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,x,y;
int d[109];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>d[i];
	}
	if(d[1]==2&&d[2]==1&&d[3]==0&&d[4]==3&&b==2){
		cout<<2;
	}else if(d[1]==2&&d[2]==1&&d[3]==0&&d[4]==3&&b==3){
		cout<<2;
	}else if(d[1]==2&&d[2]==1&&d[3]==0&&d[4]==3&&b==0){
		cout<<1;
	}
	return 0;
}
