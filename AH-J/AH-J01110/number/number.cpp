#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int x;
long long sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int size=s.size();
	for(int i=0;i<size;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=(s[i]-48);
		}
	}
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=x;i++){
		cout<<a[i];
	}
	return 0;
}
