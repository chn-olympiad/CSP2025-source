#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[1010];
	cin>>s;
	int c=s.size();
	int j=0;
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(n,n+j+1);
	for(int i=j;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}

