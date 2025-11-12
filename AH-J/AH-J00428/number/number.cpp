#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000011];
int cmp(int x,int y){
		return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	long long now=1;
	int m=s.size();
	for(int i=0;i<=m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[now]=s[i]-'0';
			now++;
		}
	}
	sort(a+1,a+now,cmp);
	for(int i=1;i<=now-1;i++){
		cout<<a[i];
	}



    return 0;
}
//8:45 tiao shi hao ruan jian ,codebl bu neng yong
//9:05 AC this problem.
