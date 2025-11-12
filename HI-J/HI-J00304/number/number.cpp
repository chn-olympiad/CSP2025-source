#include <bits/stdc++.h>
using namespace std;
string s;

int a[1000]={0};
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int n;
	int sum=0;
	cin>>s;
	for(int i=1;i<=s.size()-1;i++){
		if(s.size()==1){
			cout<<s; 
			break;
		}
		
	}
	
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			cout<<s[i];
		}
	}
	
	
	
	
	return 0;
}

