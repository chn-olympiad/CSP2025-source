#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	int k=10e6+10;
	cin>>s;
	int u[k];
	//int e=str(s);
	int p=0;
	for(int i=0;i<=k;i++){
		if(s[i]>='0' && s[i]<='9'){
			p++;
			u[p]=s[i];
		}
	}
	sort(u+1,u+p+1);
	for(int i=p;i>=1;i--){
		cout<<u[i];
	}
	return 0;
}
