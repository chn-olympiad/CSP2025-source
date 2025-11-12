#include <bits/stdc++.h>
using namespace std;
int a[1000005];//存的数字 
int cnt;//数字个数 
int ans;
int num=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';//存数字 
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
