#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int k=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int j=k;j>=1;j--){
		/*if(j=k&&a[k]==0){
			cout<<0;
			return 0;
		}*/
		cout<<a[j];
	}
	cout<<"\n";
	return 0;
}
