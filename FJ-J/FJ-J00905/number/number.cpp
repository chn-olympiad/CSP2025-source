#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long j=1;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++; 
		}
		 
	}
	sort(a+1,a+1+j);//#Shang4Shan3Ruo6Shui4
	for(int i=j;i>1;i--){
		cout<<a[i];
	}
	return 0;
 } 
