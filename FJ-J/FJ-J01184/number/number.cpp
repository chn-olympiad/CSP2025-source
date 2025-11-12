#include<bits/stdc++.h>
using namespace std;
long long a[1000005],k=1,t=1,w;
string r,s;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>r;
	for(long long i=0;r[i]!='\0';i++){
		if(r[i]>='0'&&r[i]<='9'){
			a[k]=r[i]-'0';
			k++;
		}
	}
	sort(a+1,a+1+k,cmp);
	for(long long i=1;i<=k-1;i++){
		cout<<a[i];
	}
	return 0;
}
