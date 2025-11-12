#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cmt=1;
	string s;
	cin>>s;
	s+=' ';
	for(int i=0;;i++){
		if(s[i]==' ') break;
		if(s[i]>='0' && s[i]<='9'){
			s[i]-=48;
			a[cmt]=s[i];
			cmt++;
		}
	}
	sort(a+1,a+cmt,cmp);
	for(int i=1;i<cmt;i++) cout<<a[i];
	return 0;
}
