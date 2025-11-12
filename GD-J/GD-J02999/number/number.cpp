#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(i>='0' and i<='9')a[++cnt]=int(i-'0'); 
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0; 
} 
