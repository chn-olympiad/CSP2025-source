#include<bits/stdc++.h>
using namespace std;

int a[12];
int main(){//Ê±¼ä¸´ÔÓ¶È£º11000000 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i=0;
	getline(cin,s);
	int z=s.length();
	while(z>=0){//Í° 
		if(s[z]<='9'&&s[z]>='0')// 1000000
			a[s[z]-'0']++;
		z--;
	}
	for(int j=10;j>=0;j--){//10000000
		for(int b=0;b<a[j];b++) 
		   printf("%d",j);
	}
	return 0;
} 
