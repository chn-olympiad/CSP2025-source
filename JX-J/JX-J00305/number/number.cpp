#include<bits/stdc++.h>
using namespace std;
int b[10000000],j,t;
bool cmp(int x1,int x2){
	return x1>x2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	t=a.size();
	for(int i=0;i<t;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+t,cmp);
	for(int i=0;i<j;i++){
		cout<<b[i];
	}
	return 0;
}
