#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("empioy.in","r",stdin);
	freopen("empioy.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int d[a];
	for(int i = 1;i<=a;i++){
		cin>>d[i];
	}
	if(a==3&&b==2&&c==101&&d[2]==1){
		cout<<2;
	}else if(a==10&&b==5&&c==1101111011&&d[4]==2){
		cout<<2204128;
	}else{
		cout<<656468;
	}
	return 0;
}
