#include<bits/stdc++.h>
using namespace std;
string s;
int num=0,ans=0;
string n;
char n2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			n[num]=s[i];
			num+=1;
			}
	}
	for(int i=0;i<num;i++){
		ans=i;
		for(int j=i;j<num;j++){
			if(n[ans]<=n[j])ans=j;
			}
		cout<<n[ans];
		n[ans]=n[0];
		}
}
