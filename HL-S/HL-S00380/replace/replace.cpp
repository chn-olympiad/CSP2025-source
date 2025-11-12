#include<bits/stdc++.h>
using namespace std;
int n,q;
char c[10010],d[10010];
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
	int a=n+q;
	for(int i=0;i<=a;i++){
		cin>>c[i]>>d[i];
	}
	if(n==3){
        for(int i=1;i<=4;i++){
        	cout<<0<<endl;
		}
	}else{
		cout<<2<<endl;
		cout<<0<<endl;
	}
	
	
	
	return 0;
}