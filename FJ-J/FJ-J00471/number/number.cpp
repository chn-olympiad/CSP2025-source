#include<bits/stdc++.h>
using namespace std;
bool bmp(int x,int y){
	return x>y;
}
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000000],n=0;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1,bmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
