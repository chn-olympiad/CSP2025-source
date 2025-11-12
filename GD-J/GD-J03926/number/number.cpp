#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int x[N];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int sum=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			x[sum]=(a[i]-'0');
			sum++;
		}
	}
	sort(x,x+sum,cmp);
	for(int i=0;i<sum;i++)cout<<x[i];
	return 0;
}
