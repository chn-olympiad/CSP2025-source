#include<iostream>
#include<algorithm>
using namespace std;
int b[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length(),cnt=0,xb=-1;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(b,b+n,cmp);
	for(int i=0;i<cnt;i++){
		cout<<b[i];
	}
	return 0;
}
