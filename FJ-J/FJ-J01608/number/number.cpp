#include<bits/stdc++.h>
using namespace std;
string a;
long long k=0,b[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++k]=int(a[i])-48;
		}
	}
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<b[i];
	}
	return 0;
}
