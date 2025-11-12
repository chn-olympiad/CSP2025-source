#include<bits/stdc++.h>
using namespace std;
string s;
struct node{
	int p,v=0;
}a[1000005];
bool com(node x,node y){
	return x.p>y.p;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i].p=s[i]-'0';
			a[i].v=1;
		}
	}
	sort(a,a+len,com);
	for(int i=0;i<len;i++){
		if(a[i].v==1){
			cout<<a[i].p;
		}
	}
	
	return 0;
}
