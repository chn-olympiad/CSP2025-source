#include<iostream>
#include<algorithm>
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
	int now=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			now++;
			a[now]=s[i]-'0';
		}
	}
	sort(a+1,a+now+1,cmp);
	for(int i=1;i<=now;i++) cout<<a[i];
	return 0;
}
