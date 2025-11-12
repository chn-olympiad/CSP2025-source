#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	char s;
	int i=1;
	int a[1010]={0};
	cin>>str;
	while(i<=str.length()){
		s=(char)str[i-1];
		if (s=='0' or s=='1' or s=='2' or s=='3' or s=='4' or s=='5' or s=='6' or s=='7' or s=='8' or s=='9'){
			a[i]=(int)s-47;
		}
		i++;
	}
	sort(a,a+i);
	for (int i=1000;i>=1;i--){
		if (a[i]!=0) cout<<a[i]-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}