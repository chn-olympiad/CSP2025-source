#include <bits/stdc++.h>
using namespace std;
string s;
int a[100010],n,sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			a[i]=s[i];
			a[i]-=48;
			sum++;
		}
	}

	sort(a,a+n,cmp);

	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
