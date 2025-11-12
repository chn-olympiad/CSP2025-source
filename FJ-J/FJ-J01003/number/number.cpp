#include<bits/stdc++.h>
using namespace std;
int a[1000005],c,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c++;
			a[c]=s[i]-48;			
		}
	}
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}
	return 0;
}
