#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
char c;
long long n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>c){
		if(isdigit(c)){
			ch[++n]=c;
		}
	}sort(ch+1,ch+n+1,greater<char>());
	if(ch[1]=='0'){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		cout<<ch[i];
	}
	return 0;
}
