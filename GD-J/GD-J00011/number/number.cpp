#include<bits/stdc++.h>
using namespace std;
int	num[1000006];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int si=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[si]=s[i]-'0';
			si++;
		}
	}
	sort(num,num+si,cmp);
	for(int i=0;i<si;i++){
		cout<<num[i];
	}
}
