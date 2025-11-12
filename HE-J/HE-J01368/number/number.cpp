#include<bits/stdc++.h>
using namespace std;
string s;
int sum,a,k[10^6];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6'or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			k[i] =  s[i] - 48;
		}else{
			sum ++ ;
		}	
	}	
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<s.size();j++)
		{
			if(k[i]>=k[j])
			{
			 a = k[i];
			 k[i] = k[j];
			 k[j] = a;	
			} 
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(sum>0 and k[i]==0)
		{
			sum--;
		}else{
			cout << k[i];
		}
	}
}
