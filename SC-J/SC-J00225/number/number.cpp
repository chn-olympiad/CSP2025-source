#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={};
	for(int i=0;i<s.size();i++){
		int x=s[i];
		if(x=='0') a[0]++;
		else if(x=='1') a[1]++;
		else if(x=='2') a[2]++;
		else if(x=='3') a[3]++;
		else if(x=='4') a[4]++;
		else if(x=='5') a[5]++;
		else if(x=='6') a[6]++;
		else if(x=='7') a[7]++;
		else if(x=='8') a[8]++;
		else if(x=='9') a[9]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 