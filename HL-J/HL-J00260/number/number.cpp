#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)return x>y;
 	
string s;
int a[1010],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			for(int i=1;i<=n;i++){
				a[i]++;
				a[i]=s[i]-'0';
				sort(a+1,a+n+1,cmp);
			}
			cout<<a[i];
		}
    } 
}
   
