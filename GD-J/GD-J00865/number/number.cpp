#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

const int N=1e6+5;
string s;
int a[11]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			int g=c-'0';a[g]++;
		}
	}
	for(int i=9;i>=0;i--){
		//if(a[g]==0) continue;
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0; 
} 
