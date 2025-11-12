#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	cin>>s;
	int c=s.size();
	char a[c];
	for(i=0;i<c;i++){
		a[i]=s[i];
	}
	sort(a,a+c,cmp);
	for(i=0;i<c;i++){
		if(a[i]>='0' and a[i]<='9'){
			cout<<a[i];
		}
	}
	return 0;
}
