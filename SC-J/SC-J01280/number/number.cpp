#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
char ss[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss[sum]=s[i];
			sum++;
		}
	}
	sort(ss,ss+sum);
	for(int i=sum-1;i>=0;i--){
		cout<<ss[i];
	}
	return 0;
}