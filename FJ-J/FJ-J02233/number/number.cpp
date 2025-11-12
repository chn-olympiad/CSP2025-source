#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	int l=1;
	for(int i=0;i<strlen(ch);i++){
		if(ch[i]>='0'&&ch[i]<='9'){
			a[l]=ch[i]-48;
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>=1;i--)cout<<a[i];
	return 0;
}
