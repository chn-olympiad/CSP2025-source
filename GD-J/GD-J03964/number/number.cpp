#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100005];
	int n=s.size();
	int j=1;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=int(s[i]-'0');
			j++;
		}
	}

	sort(a+1,a+j+1);
	for(int i=j;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 
