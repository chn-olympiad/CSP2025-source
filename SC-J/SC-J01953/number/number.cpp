#include <bits/stdc++.h>
using namespace std;
int a[1000006],idx;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[idx++]=s[i]-48;
		}
	}
	sort(a,a+idx,cmp);
	for(int i=0;i<idx;i++){
		cout <<a[i];
	}
	return 0;
} 