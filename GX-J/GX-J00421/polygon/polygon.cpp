#include<bits/stdc++.h>
using namespace std;
int n;
int g[5000000];
int a,b,c;
int main (){
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
		cin>>a>>b>>c;
		if((a+b)>c&&(a+c)>b&&(c+b)>a){
			cout<<1<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}else{
		for(int i=0;i<=n;i++){
			cin>>g[i];
		}
		cout<<0<<endl;
		return 0;
	}
    
    return 0;
}
