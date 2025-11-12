#include <bits/stdc++.h>
using namespace std;
string n;
long long a[1000003];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>n;
	long long cnt=1;
	for(long long i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			if(n[i]=='0')a[cnt]=1;
			if(n[i]=='1')a[cnt]=2;
			if(n[i]=='2')a[cnt]=3;
			if(n[i]=='3')a[cnt]=4;
			if(n[i]=='4')a[cnt]=5;
			if(n[i]=='5')a[cnt]=6;
			if(n[i]=='6')a[cnt]=7;
			if(n[i]=='7')a[cnt]=8;
			if(n[i]=='8')a[cnt]=9;
			if(n[i]=='9')a[cnt]=10;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt-1;i++){
		cout<<a[i]-1;
	}
	return 0;
}
