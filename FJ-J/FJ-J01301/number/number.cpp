#include<bits/stdc++.h>
using namespace std;	
int u[1000001],cnt=1;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			u[cnt++]=int(a[i])-48;
		}
	}
	cnt-=1;
	sort(u+1,u+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<u[i];
	}
	return 0;
} 
