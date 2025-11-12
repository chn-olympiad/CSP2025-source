#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[1000006],flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			flag++;
			a[flag]=s[i]-'0';
		}
	}
	sort(a+1,a+flag+1,cmp);
	for(int i=1;i<=flag;i++) cout<<a[i];
}
