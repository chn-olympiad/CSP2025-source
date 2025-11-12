#include<bits/stdc++.h>
using namespace std;
string s;
char a[2000000];
long long l;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>> s;
	long long b=s.size();
	for(long long i=0;i<b;i++){
		if(s[i]>='0' && s[i]<='9'){
			l++;
			a[l]=s[i];
		}
	}
	sort(a+1,a+1+l,cmp);
	for(long long i=1;i<=l;i++){
		cout<< a[i];
	}
	return 0;
}
