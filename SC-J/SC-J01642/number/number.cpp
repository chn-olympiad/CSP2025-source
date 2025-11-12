#include<iostream>
#include<algorithm> 
using namespace std;
const int N=1e6+5;
int cnt=0,cnt1=0,num1[N];
char num[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	while(cin>>num[++cnt]){
		if(num[cnt]<='9'&&num[cnt]>='0')
		num1[++cnt1]=num[cnt]-'0';
	}
	
	sort(num1+1,num1+cnt1+1,cmp);
	for(int i=1;i<=cnt1;i++)cout<<num1[i];
	return 0;
}