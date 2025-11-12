#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int j=1;
bool cmp(char x,char y){
	if(x>=y)return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++)cout<<a[i];
	return 0;
}
