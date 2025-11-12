#include<bits/stdc++.h>
using namespace std;
#define int  long long


string s;
int a[1000100];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	int t=s.size(),m=1;
	
	for(int i=0;i<t;++i){
		if( (int)s[i]>=48 && (int)s[i]<=57 ){
			a[m]=(int)s[i]-48;
			m++;
			}
	}
	sort(a+1,a+m);
	
	if(a[m-1]==0){
		cout<<0;
		return 0;
		}
	
	
	for(int i=m-1;i>=1;--i){
		cout<<a[i];
	}
	
	
	return 0;
}
