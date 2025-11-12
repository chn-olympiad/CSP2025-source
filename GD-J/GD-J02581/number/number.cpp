#include<bits/stdc++.h>
using namespace std;
long long n;
char a[100001];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	n=str.length();
	int l=0;
	for(long long i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[l]=str[i];
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--) cout<<a[i];
	return 0;
} 
