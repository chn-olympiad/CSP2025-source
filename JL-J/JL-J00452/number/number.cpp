#include <bits/stdc++.h>
using namespace std;
long long s,sw[1000001],chu=1,cheng=1,num=0,i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<10;i++){
		sw[i]=s/chu%10;
		chu*=10;
	}
	sort(sw,sw+10);
	for(i=0;i<10;i++){
		int f=0;
		sw[i]*=cheng;
		num+=sw[i];
		cheng*=10;
		while(sw[i]==0) i++,f=1;
		if(f) i--;
	}
	cout<<num/10<<endl;
	return 0;
}
