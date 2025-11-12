#include<bits/stdc++.h>
using namespace std;
string s="";
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b,x=0;
	b=a.size();
	int c[b+100];
	for(int i=1;i<=b+10;i++){
		c[i]=0;
	}
	for(int i=0;i<b;i++){
		if(a[i]<='9'&&a[i]>='0'){
			x++;
			c[x]=a[i]-'0';
			
		}
	}
	sort(c+1,c+x+1,cmp);
	for(int i=1;i<=x;i++){
		s+=(c[i]+'0');
	}
	cout<<s;
	return 0;
}