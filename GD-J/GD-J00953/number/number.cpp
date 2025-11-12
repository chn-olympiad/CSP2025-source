#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

string a[N];
int k=0;
bool cmp(string x,string y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			k++;
			a[k]=s[i];
			
		}
	}
	sort(a+1,a+k+1,cmp);
	int num=0;
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	
	
	return 0;
}

