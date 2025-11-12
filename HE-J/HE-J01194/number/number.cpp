#include<bits/stdc++.h>
using namespace std;
string n,m;
int z,x,c[1000010],a;
bool qwe(int q,int w){
	return q>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int x=n.size();
	for(int i=0;i<x;i++){
		if(n[i]>='0'&&n[i]<='9'){
			if(n[i]=='0'){
				
			}else{
				a=1;
			}
			c[++z]=n[i]-'0';
		}
	}sort(c+1,c+1+z,qwe);
	if(a==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=z;i++){
		cout<<c[i];
	}
	
	
	
	return 0;
} 
