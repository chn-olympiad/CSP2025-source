#include<bits/stdc++.h>
const int maxn=1000005;
using namespace std;
string Scout;
int Logos;
int Top=1;
int a[maxn];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>Scout;
	Logos=Scout.size();
	for(int i=0;i<Logos;i++){
		if(Scout[i]<='9'&&Scout[i]>='0'){
			a[Top]=Scout[i]-'0';
			Top++;
		}
	}
	sort(a+1,a+Top,cmp);
	for(int i=1;i<Top;i++){
		cout<<a[i];
	}
	return 0;
}