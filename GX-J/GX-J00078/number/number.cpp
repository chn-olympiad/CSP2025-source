#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],b=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b,cmp);
	for(int i=0;i<b;i++){
		cout<<a[i];
	}

	return 0;
}
