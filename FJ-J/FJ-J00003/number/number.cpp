#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
int number[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size()-1;
	for(int i=0;i<=n;i++){
		char ch=s[i];
		if(ch>='0' && ch<='9')number[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=number[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}

