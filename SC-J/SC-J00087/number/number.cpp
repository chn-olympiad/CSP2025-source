#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int k=1;
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	k--;
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
}