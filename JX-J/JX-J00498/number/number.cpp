#include<bits/stdc++.h>
using namespace std;
char a;
int b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a=='9') b[9]++;
		if(a=='8') b[8]++;
		if(a=='7') b[7]++;
		if(a=='6') b[6]++;
		if(a=='5') b[5]++;
		if(a=='4') b[4]++;
		if(a=='3') b[3]++;
		if(a=='2') b[2]++;
		if(a=='1') b[1]++;
		if(a=='0') b[0]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
