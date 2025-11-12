#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[1000005],lo=s.size(),num=0;
	for(int i=0;i<lo;i++){
		if(s[i]>=48&&s[i]<=57){
			num++;
			a[num]=(int)s[i]-48;
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}
