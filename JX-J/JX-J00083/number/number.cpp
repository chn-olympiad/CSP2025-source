#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int a[1000005];
ll len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=int(s[i])-48;
		}
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
