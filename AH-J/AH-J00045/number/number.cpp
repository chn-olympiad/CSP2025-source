#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size(),x=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=int(s[i]-'0');
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--) cout<<a[i];
	cout<<endl;
	return 0;
}





































//QAQ回去写游记了
