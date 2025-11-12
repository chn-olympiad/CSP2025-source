#include<bits/stdc++.h>
using namespace std;
string em,e;
int n,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,em);
	int em1=em.size();
	for(int i=0;i<em1;i++){
		n=-10;
		for(int j=0;j<em1;j++){
			if(em[j]-'0'>n&&em[j]>='0'&&em[j]<='9'){
				n=em[j]-'0';
				ans=j;
			}
		}
		if(n==-10){
			break;
		}
		e+=em[ans];
		em[ans]='#';
	}
	cout<<e;
}
