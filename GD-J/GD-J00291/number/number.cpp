#include<bits/stdc++.h>
using namespace std;
long long bo[91];
string s;
bool h=true; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			bo[s[i]-'0']++;
	int i=9;
	while(i>=0){
		if(bo[i]>0){
			if(i==0&&h) break;
			for(int j=1;j<=bo[i];j++)
				cout<<i;
			h=false;
		}
		i--;
	}
	if(h) cout<<0;
	return 0;
}
