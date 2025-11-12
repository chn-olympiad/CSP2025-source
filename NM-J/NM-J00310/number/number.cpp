#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn];
int cmp(int a,int b){
return a>b;
}
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.size(),num=0;
	for(int i=0;i<len;i++){
		if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'){
			continue;
		}
		else{
		if(s[i]=='0'){a[num]=0;num++;}
		if(s[i]=='1'){a[num]=1;num++;}
		if(s[i]=='2'){a[num]=2;num++;}
		if(s[i]=='3'){a[num]=3;num++;}
		if(s[i]=='4'){a[num]=4;num++;}
		if(s[i]=='5'){a[num]=5;num++;}
		if(s[i]=='6'){a[num]=6;num++;}
		if(s[i]=='7'){a[num]=7;num++;}
		if(s[i]=='8'){a[num]=8;num++;}
		if(s[i]=='9'){a[num]=9;num++;}
	}
	}
	sort(a,a+num,cmp);
	for(int i=0;i<num;i++) {
		if(a[i]>=0)cout<<a[i];
		else continue;
	}
	return 0;
}
