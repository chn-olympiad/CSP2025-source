#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],t=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[t++]=a[i]-'0';
		}
	}
	sort(b+1,b+t,cmp);
	for(int i=1;i<t;i++){
		cout<<b[i];
	}
	return 0;
}
