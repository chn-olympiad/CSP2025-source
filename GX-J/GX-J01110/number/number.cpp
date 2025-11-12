#include<bits/stdc++.h>
using namespace std;
string s;
int k,a[1000005],ans;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=s.size();
	for(int i=0;i<c;i++){
			if(s[i]>='0'&&s[i]<='9'){
				a[k]=s[i]-48;
				k++;
			}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
}
