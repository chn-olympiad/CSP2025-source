#include<bits/stdc++.h>
using namespace std;
long long a,s,d[100000],f=0,g,h,j,k,l;
char c[10000000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(long long p=0;c[p];p++){
		if(c[p]>='0'&&c[p]<='9'){
			d[f++]=c[p]-'0';
		}
	}
	sort(d,d+f,cmp);
	if(d[0]==0){
		cout<<0;
		return 0;
	}
	for(long long p=0;p<f;p++){
		cout<<d[p];
	}
	return 0;
}
