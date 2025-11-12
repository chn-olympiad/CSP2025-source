#include<bits/stdc++.h>
using namespace std;
string a;
int num[1000005],idx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w,",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9')num[++idx]=a[i]-'0';
	}
	sort(num+1,num+1+idx);
	for(int i=idx;i>=1;i--)cout<<num[i];
	return 0;
}
	
