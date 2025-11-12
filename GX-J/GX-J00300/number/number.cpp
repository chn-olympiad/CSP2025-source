#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	char a[len]={};
	int mot=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
		a[mot]=s[i];
		mot++;
	}
	}
    sort(a,a+len,cmp);
    for(int i=0;i<len;i++){
		cout<<a[i];
		}
		return 0;
	}
