#include<bits/stdc++.h>
using namespace std;
#define int long long
int j[1000010];
bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int g=0,a=0,f=0;
	for(int i=0;i<=s.size()-1;i++){
		j[i]=s[i]-'0';
		if(j[i]>=0&&j[i]<=9){
			f++;
		}else{
			j[i]=0;
		}
	}
	sort(j,j+s.size(),cmp);
	for(int i=0;i<=f-1;i++){
		a=a*10+j[i];
	}
	cout<<a;
	return 0;
}
