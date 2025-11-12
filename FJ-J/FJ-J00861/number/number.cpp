#include <bits/stdc++.h>
using namespace std;
string s,ans;
int n,len;
int a[1000010];
bool f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++){
		if (s[i]>='0'&&s[i]<='9'){
			len++;
			a[len]=(s[i]-'0');
		}
	}
	sort(a+1,a+len+1,cmp);
	for (int i=1;i<=len;i++){
		if (a[i]==0) f=1;
		else break;
	}
	if (f==1){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=len;i++){
		ans+=(a[i]+'0');
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
