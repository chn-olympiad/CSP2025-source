#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+5;
int a[N],cnt,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof a);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			c++;
			//cout<<a[cnt]<<" "<<c<<endl;
		}
		cnt++;
	}
	sort(a+0,a+s.size(),cmp);
	for(int i=0;i<c;i++)cout<<a[i];
	return 0;
}
