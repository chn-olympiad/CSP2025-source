#include<bits/stdc++.h>
using namespace std;
string ssr;
int flag=0;
char aaa[1000005];
int ccc[1000005];
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ssr;
	int num=ssr.size();
	for(int i=0;i<num;i++){
		if(ssr[i]>='0'&&ssr[i]<='9'){
			flag++;
			aaa[flag]=ssr[i];
		}
	}
	for(int i=1;i<=flag;i++){
		ccc[i]=int(aaa[i])-48;
	}
	sort(ccc+1,ccc+1+flag);
	for(int i=flag;i>=1;i--){
		cout<<ccc[i];
	}
	return 0;
} 
