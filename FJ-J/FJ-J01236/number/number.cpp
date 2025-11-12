#include <bits/stdc++.h>
using namespace std;
string a;
long long num[1000005];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int x=0;
	for (int i=0;i<a.size();i++){
		if (a[i]>='0' && a[i]<='9'){
			num[x]=a[i]-48;
			x++;
		}
	}
	sort(num,num+x,cmp);
	for (int i=0;i<x;i++){
		cout<<num[i];
	}
	return 0;
}

