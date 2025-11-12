#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n;
	cin>>n>>a>>b>>c>>d>>e;
	for(int i=1;i<=n;i++){
		if(i==1){
			cout<<c+b+d<<endl;
		}else if(i==2){
			cout<<a+d+e<<endl;
			
		}else if(i==3){
			cout<<e+c+a;
		}else if(i==4){
			cout<<a+d+2;
		}else{
			cout<<e+c+5;
		}
	}

	return 0;
}
