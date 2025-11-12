#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int a[1000001]={0};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),t=0;
	for(int i=0;i<=l;i++){
		if(s[i]>='0' && s[i]<='9'){
			t++;
			a[t]=s[i];
			a[t]-=48;
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
