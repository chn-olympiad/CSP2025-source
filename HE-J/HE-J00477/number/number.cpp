#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
		}else{
			a[i]=-1;
		}
	}
	sort(a,a+s.size(),cmp);
	int i=0;
	while(a[i]!=-1){
		cout<<a[i];
		i++;
	}
	return 0;
}
