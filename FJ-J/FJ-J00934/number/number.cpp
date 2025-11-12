#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
int a[N],tot,len;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

