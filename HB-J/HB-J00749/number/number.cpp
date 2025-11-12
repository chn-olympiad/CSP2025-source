#include<bits/stdc++.h>
using namespace std;
string s;
int k[100010000],cnt;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k[i]=s[i]-'0';
			cnt++;
			//cout<<k[i]<<" ";
		}
		//else
			//s[i]=' ';
		//cout<<s[i]<<endl;
		
	}
	sort(k,k+len,cmp);
	for(int i=0;i<cnt;i++)
	{
		//if(s[i]-'0'==0)
			//continue;
	
		cout<<k[i];
	}
	return 0;
}
