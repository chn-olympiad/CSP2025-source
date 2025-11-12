#include<bits/stdc++.h> 
using namespace std;
int a[100005];
int ping(int cnt){
	int maxx=0;
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
		cout<<a[i];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	ping(cnt);
	return 0;
}