#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int p = 1;
bool c(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=(int)s[i]-'0';
			p++;
		}
	}
	p-=1;
	sort(a+1,a+p+1,c);
	for(int i=1;i<=p;i++){
		cout<<a[i];
	}
	return 0;
}