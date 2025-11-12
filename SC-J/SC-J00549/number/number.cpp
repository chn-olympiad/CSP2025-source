#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	memset(b,0,sizeof(b));
	int len=a.size();
	int sum=0;
	for(int i=0;i<len;i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			sum++;
			b[sum]=int(a[i])-48;
		}
	}
	sort(b+1,b+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		cout<<b[i];
	}
	return 0;
} 