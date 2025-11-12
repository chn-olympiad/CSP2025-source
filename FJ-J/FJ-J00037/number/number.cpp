#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
string a;
int lena,sum=0,s[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	lena=a.length();
	for(int i=0;i<lena;i++){
		if(a[i]>='0' && a[i]<='9'){
			sum++;
			s[sum]=a[i];
		}
	}
	sort(s+1,s+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<s[i]-48;
	}
	return 0;
}
