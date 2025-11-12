#include<iostream>
#include<algorithm>
using namespace std;
char t[1000007],s[1000007];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	cin>>s;
	for(int i=0;s[i];++i){
		if(s[i]>='0'&&s[i]<='9')
			t[++cnt]=s[i];
	}
	sort(t+1,t+cnt+1,greater<char>());
	for(int i=1;t[i];++i) cout<<t[i];
	return 0;
}
