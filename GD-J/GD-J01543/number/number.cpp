#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1000000;
string s;
char a[N+5];
int n;
bool cmp(char l,char r){
	return (int)(l)>(int)(r); 
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.size();
	s = ' '+s;
	for(int i =1;i<=n;i++){
		a[i] = s[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i =1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			cout<<a[i];
		}
	}
	return 0;
} 
