#include<bits/stdc++.h>
using namespace std;
int main(){
	/*int n;
	srand(time(0));
	n=range()%100+1;
	cout<<n;*/
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[10]={0,0,0,0,0,0,0,0,0,0};
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			//cout<<a[i]<<" ";
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}