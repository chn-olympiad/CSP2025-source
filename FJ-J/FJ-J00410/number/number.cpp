#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n=1;

bool cmp(int x,int y){
	return x>y || x==y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='0') a[n++] = 0;
		else if(s[i]=='1') a[n++] = 1;
		else if(s[i]=='2') a[n++] = 2;
		else if(s[i]=='3') a[n++] = 3;
		else if(s[i]=='4') a[n++] = 4;
		else if(s[i]=='5') a[n++] = 5;
		else if(s[i]=='6') a[n++] = 6;
		else if(s[i]=='7') a[n++] = 7;
		else if(s[i]=='8') a[n++] = 8;
		else if(s[i]=='9') a[n++] = 9;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
		cout<<a[i];
	return 0;
} 
