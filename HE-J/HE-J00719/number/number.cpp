#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int l=s.size();
	int f=0;
	for(int i=0;i<l;i++)if(s[i]<='9'&&s[i]>='0')a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(a[i]){
			if(i!=0)f=1;
			a[i]--;
			if(f)cout<<i;
		}
	}
	if(!f)cout<<0;
	return 0;
}

