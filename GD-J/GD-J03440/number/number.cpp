#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int l,b[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(!isdigit(s[i])){
			continue;
		}
		else{
			b[++cnt]=s[i]-'0';
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",b[i]);
	}
    return 0;
}
