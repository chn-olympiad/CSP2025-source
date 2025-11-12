#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int n=s.size()-1,j=0;
	for(int i=0;i<=n;i++){
		if(s[i]>='0' && s[i]<='9')
			a[++j]=int(s[i]-'0');
	}
	sort(a+1,a+j+1);
	for(int i=j;i>0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
