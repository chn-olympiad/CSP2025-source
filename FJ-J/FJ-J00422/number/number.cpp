#include<bits/stdc++.h>
using namespace std;
string a;
long long sd[1000001];
int cut=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int lena=a.size();
	for(int i=0;i<lena;i++){
		if(a[i]>='0'&&a[i]<='9'){
			sd[++cut]=a[i]-'0';
		}
	}
	sort(sd+1,sd+1+cut,cmp);
	for(int i=1;i<=cut;i++){
		cout<<sd[i];
	}
	return 0;
}
