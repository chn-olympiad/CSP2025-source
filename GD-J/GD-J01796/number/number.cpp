#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
bool check(char s){
	if(s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9'||s=='0'){
			return true;
	}
	return false;
}
int change(char p){
	if(p=='1') return 1;
	if(p=='2') return 2;
	if(p=='3') return 3;
	if(p=='4') return 4;
	if(p=='5') return 5;
	if(p=='6') return 6;
	if(p=='7') return 7;
	if(p=='8') return 8;
	if(p=='9') return 9;
	if(p=='0') return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100002],x=0;
	memset(a,-1,sizeof(-1));
	string ss;
	cin>>ss;
	for(int i=0;i<ss.length();i++){
		char s=ss[i];
		if(check(s)){
			a[x]=change(s);
			x++;
		}
	}
	sort(a,a+ss.length()-1,cmp);
	for(int i=0;i<ss.length()-(ss.length()-x);i++){
		cout<<a[i];
	}
	return 0;
}
