#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+5;
int num[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	memset(num,0,sizeof(num));
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if((int)s[i]==48||(int)s[i]==49||(int)s[i]==50||(int)s[i]==51||(int)s[i]==52||(int)s[i]==53||(int)s[i]==54||(int)s[i]==55||(int)s[i]==56||(int)s[i]==57){
			k++;
			num[k]=(int)s[i]-48;
			cout<<num[k];
		}
	}
	
	sort(num+1,num+k+1,cmp);
	
	for(int i=1;i<=k;i++){
		cout<<num[i];
	}
	
	return 0;
}
