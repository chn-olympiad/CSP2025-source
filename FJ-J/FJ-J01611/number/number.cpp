#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
ll l,i,j,k,x[2000];
ll ctoi(char a){
	return a-'0';
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			x[k++]=ctoi(a[i]);
		}
	}
	sort(x,x+k,cmp);
	for(i=0;i<k;i++){
		printf("%lld",x[i]);
	}
	return 0;
}
