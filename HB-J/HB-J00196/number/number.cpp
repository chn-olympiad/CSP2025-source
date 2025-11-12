#include<bits/stdc++.h>
using namespace std;
bool map(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	int a=0,t=0;
	string s,n;
	cin>>s;
	for(int i=0;i<1000000;i++){
		if(s[i]!=97&&s[i]!=98&&s[i]!=99&&s[i]!=100&&s[i]!=101&&s[i]!=102&&s[i]!=103&&s[i]!=104&&s[i]!=105&&s[i]!=106&&s[i]!=107&&s[i]!=108&&s[i]!=109&&s[i]!=110&&s[i]!=111&&s[i]!=112&&s[i]!=113&&s[i]!=114&&s[i]!=115&&s[i]!=116&&s[i]!=117&&s[i]!=118&&s[i]!=119&&s[i]!=120&&s[i]!=121&&s[i]!=122){
			n[a]=s[i];
			a++;
		}
	}
	sort(n,n+a,map);
	for(int i=0;i<a;i++){
		for(int j=a-1;j>0;j--){
			for(int x=j;x>0;x--){
				n[i]=n[i]*10
			}
		}
	}
	for(int i=0;i<a;i++){
		t=t+n[i];
	}
	cout<<t;
	return 0;
}
