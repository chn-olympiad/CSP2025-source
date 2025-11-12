#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()+10]={0};
	long long g=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||
		   s[i]=='3'||s[i]=='4'||s[i]=='5'||
		   s[i]=='6'||s[i]=='7'||s[i]=='8'||
		   s[i]=='9'){
			a[g]=s[i]-'0';
			g++;
		}
	}
	int zd=INT_MIN,zds;
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			if(a[j]>=zd&&a[j]>=0){
				zd=a[j];
				zds=j;
			}
		}
		cout<<a[zds];
		a[zds]=-1;
		zd=INT_MIN; 
	} 
	return 0;
}
 
