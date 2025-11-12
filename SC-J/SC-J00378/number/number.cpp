#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
string s;
int a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,0,sizeof a);
	int n=s.size();
	int k=0;
	for(int i=0;i<=n-1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	else{
		sort(a+1,a+k+1);
		for(int i=k;i>=1;i--)
			cout<<a[i];
	}
	return 0;
}