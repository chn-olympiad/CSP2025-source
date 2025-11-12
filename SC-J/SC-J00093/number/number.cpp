#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string sq[N];
char a[N];
int n=0,m;
char ch[N];
int main(){
	while(cin>>ch){
		n++;
		for(int i=1;i<=n;++i){
			if(ch[i]<='0'||ch[i]>='9'){
			ch[i]=' ';
			break;
			//cout<<ch;
			//continue;
		}
		if(ch[i]>='0'||ch[i]<='9'){
			if(ch[i]>ch[i-1]); 
			swap(ch[i],ch[i-1]);
			ch[i]=ch[i];
			//continue;
		}
		cout<<ch[n];
	}
}
	return 0;
}