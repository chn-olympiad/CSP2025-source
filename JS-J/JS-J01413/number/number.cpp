#include<bits/stdc++.h>
using namespace std;
string s;
int l;
char a[1000010];
bool cmp(char x,char y){
	return x>y;
	}
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	l=s.size();
	int m=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++m]=s[i];
			}
		}
	sort(a+1,a+m+1,cmp); 
	for(int i=1;i<=m;i++){
		cout<<a[i];
		}
	return 0;
}

