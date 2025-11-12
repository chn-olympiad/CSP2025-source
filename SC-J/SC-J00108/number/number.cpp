#include<iostream>
using namespace std;
long long length(string s){
	int n=0;
	while(s[n]) n++;
	return n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[10]={};
	string ss;
	cin>>ss;
	long long n=length(ss);
	while(n>=0){
		if(ss[n]=='0') s[0]++;
		if(ss[n]=='1') s[1]++;
		if(ss[n]=='2') s[2]++;
		if(ss[n]=='3') s[3]++;
		if(ss[n]=='4') s[4]++;
		if(ss[n]=='5') s[5]++;
		if(ss[n]=='6') s[6]++;
		if(ss[n]=='7') s[7]++;
		if(ss[n]=='8') s[8]++;
		if(ss[n]=='9') s[9]++;
		n--; 
	}
	for(int i=9;i>=0;i--){
		while(s[i]>0){
			cout<<i;
			s[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}