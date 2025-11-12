#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[1000000],b[1000000],c;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a=1;
	for(int i=1;i<=1;i++){
		cin>>s[i];
		if(s[i]>="0"&&s[i]<="9"){
			b[a]=s[i];
			a++;
		}
		}
	for(int y=0;y<=a+1;y++){
		if(b[y-1]>b[y]){
			b[y-1]=c;
			c=b[y];
			b[y]=b[y-1];
		}
		cout<<b[y];
		
	}
	return 0;
} 