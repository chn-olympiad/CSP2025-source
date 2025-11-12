#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
