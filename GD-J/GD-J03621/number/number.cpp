#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n[N],a[11];
long long num,i,j;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			num++;
		}
	}
	j=1;
	for(i=9;i>=0;i--){
		while(a[i]){
			n[j++]=i;
			a[i]--;
		}
	}
	n[j--]=-1;
	i=1;
	while(n[i]==0&&i<j){
		i++;
	}
	for(;i<=num;i++){
		cout<<n[i];
	}
	return 0;
}
