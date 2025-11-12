//luogu:1623332
//F 
#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt=0,num[1000005];
int main(){
//	freopen("number1.in","r",stdin);
//	freopen("number1.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<1e6+3;i++){
		if(a[i]>='0'&&a[i]<='9') cnt++,num[cnt]=int(a[i]-'0');
		
	}sort(num+1,num+1+cnt);
	for(int j=0;j<cnt;j++){
		cout<<num[cnt-j];
	}
	return 0; 
}//U
//dif:red
//18min 100pts
