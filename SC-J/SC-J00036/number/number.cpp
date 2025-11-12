#include<bits/stdc++.h>
using namespace std;
string s;
char x[10]={'0','1','2','3','4','5','6','7','8','9'};
int n[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long a=s.size();
	long long y=0;
    for(int i=0;i<a;i++){
		for(int j=0;j<10;j++){
			if(s[i]==x[j]){
			    n[y]=s[i]-48;
				y++;	
			}
		}
	}
	sort(n,n+y);
	for(int i=y-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
} 