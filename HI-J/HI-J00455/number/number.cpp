#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N],number[N];
int nlong=0;
bool cmp(char a,char b){
	return int(a)>int(b);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=s[i];
	}
	int t=1;
	for(int i=0;i<s.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			nlong++;
			number[t]=a[i];
			t++;
		}
	}
	sort(number+1,number+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<number[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
