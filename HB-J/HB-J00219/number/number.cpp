#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i]-48;
		}
	}
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans;i++){
		cout<<a[i];
	}
	return 0;
}
