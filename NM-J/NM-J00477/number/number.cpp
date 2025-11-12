#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	string::iterator it;
	cin>>a;
	int num[1000000];
	int base=0;
	for(it=a.begin();it!=a.end();it++){
		if(*it>='0'&&*it<='9'){
			num[base++]=*it-'0';
		}
	}
	sort(num,num+base,cmp);
	for(int i=0;i<base;i++)
		cout<<num[i];
	return 0;
}
