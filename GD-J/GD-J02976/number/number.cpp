#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int i,j=0;
string a;
int b[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=(a[i]-'0');
			j++;
		}
	}
	sort(b,b+j,cmp);
	for(i=0;i<j;i++){
		cout<<b[i];
	}
	return 0;
}

