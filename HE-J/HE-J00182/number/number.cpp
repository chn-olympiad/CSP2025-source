#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e6+10;
string s;
int a[N],l=1;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[l]=s[i]-'0';
//			cout<< a[l];
			l++;
		}
	}
	sort(a+1,a+l,c);
	if(a[1]==0)
		return 0;
	for(int i=1;i<l;i++){
		cout<< a[i];
	}
	return 0;
}
//lec3v4
