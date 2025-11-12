#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5; 
int a[MAXN];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	int c=0;
	for(int i=0;i<t.size();i++){
		if(t[i]>='0'&&t[i]<='9'){
			a[c]=(int)t[i]-48;
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}