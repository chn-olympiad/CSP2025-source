#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=0,m=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-48;
			p++;
			m++;
		}
	}
	sort(a+0,a+p,cmp);
	for(int i=0;i<p;i++){
		cout<<a[i];
	}
} 
