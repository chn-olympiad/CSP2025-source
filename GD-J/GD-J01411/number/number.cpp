#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')a0++;
		else if(s[i]=='1')a1++;
		else if(s[i]=='2')a2++;
		else if(s[i]=='3')a3++;
		else if(s[i]=='4')a4++;
		else if(s[i]=='5')a5++;
		else if(s[i]=='6')a6++;
		else if(s[i]=='7')a7++;
		else if(s[i]=='8')a8++;
		else if(s[i]=='9')a9++;
	}
	while(a9--)printf("9");
	while(a8--)printf("8");
	while(a7--)printf("7");
	while(a6--)printf("6");
	while(a5--)printf("5");
	while(a4--)printf("4");
	while(a3--)printf("3");
	while(a2--)printf("2");
	while(a1--)printf("1");
	while(a0--)printf("0");
	return 0;
}
