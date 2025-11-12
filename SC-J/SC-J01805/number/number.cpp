#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int q[N],num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			q[num]=(s[i]-'0');
		}
	}
	sort(q+1,q+1+num,cmp);
	for(int i=1;i<=num;i++){
		cout<<q[i];
	}
	return 0;
} 