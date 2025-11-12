#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1005],n;
int main(){
	/*freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);*/
	cin>>s;
	n=s.size();
	int t=1;
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t+1);
	while(t>1){
		cout<<a[t];
		t--;
	}
	return 0;
}
