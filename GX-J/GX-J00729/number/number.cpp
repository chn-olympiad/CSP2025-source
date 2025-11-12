#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cnt=s.size();
	for(int i=1;i<cnt;i++){
		if(s[i]=='9') a[i]++;
		else if(s[i]=='8') a[i]++;
		else if(s[i]=='7') a[i]++;
		else if(s[i]=='6') a[i]++;
		else if(s[i]=='5') a[i]++;
		else if(s[i]=='4') a[i]++;
		else if(s[i]=='3') a[i]++;
		else if(s[i]=='2') a[i]++;
		else if(s[i]=='1') a[i]++;
	}
	for(int i=9;i>=1;i--){
		while(a[i]--){
			cout<<a[i];
		}
	}
	return 0;
}
