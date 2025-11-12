#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int cnt=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	//memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			//cout<<s[i];
			a[++cnt]=s[i]-48;
			//cout<<a[cnt];
		}
	}
	sort(a,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
