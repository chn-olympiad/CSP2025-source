#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],n,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long num=s.size();
	for(long long  i=0;i<num;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(long long  i=n;i>=1;i--){
		cout<<a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
