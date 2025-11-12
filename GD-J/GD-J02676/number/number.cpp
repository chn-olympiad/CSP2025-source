#include<bits/stdc++.h>
using namespace std;
string st;
int n,m,a[1145140],t,f,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	n=st.size();
	st='#'+st;t=0;
	for(int i=1;i<=n;i++)
		if('0'<=st[i]&&st[i]<='9'){
			a[++t]=int(st[i]-'0');
			if(f==0&&a[t]!=0)f=1;
		}
	if(!f){cout<<'0';return 0;}
	sort(a+1,a+t+1);
	while(t>0){
		cout<<a[t--];
	}
	return 0;
} //#Shang4Shan3Ruo6Shui4
