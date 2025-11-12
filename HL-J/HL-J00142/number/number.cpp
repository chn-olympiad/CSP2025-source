#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]-'0'==0||a[i]-'0'==1||a[i]-'0'==2||a[i]-'0'==3||a[i]-'0'==4||a[i]-'0'==5||a[i]-'0'==6||a[i]-'0'==7||a[i]-'0'==8||a[i]-'0'==9){
			b[i]=a[i]-'0'-10;
		}
		
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++){
		if(b[i]!=0){
			cout<<b[i]+10;
		}
		
	}
	return 0;
}
