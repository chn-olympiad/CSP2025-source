#include<bits/stdc++.h>
using namespace std;

int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int tot=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tot]=(int)s[i]-'0';
			tot++;
		}
	}
	tot--;
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

