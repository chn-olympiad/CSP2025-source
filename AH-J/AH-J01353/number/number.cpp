#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int l,a[N],f,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			if(s[i]!='0')
				f=1;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	if(f==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--)
		cout<<a[i];
		
}
