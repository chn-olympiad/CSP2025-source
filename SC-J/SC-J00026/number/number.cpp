#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long num[100005],k=0;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		int x=s[i]-'0';
		if(x>=0&&s[i]-'0'<=9){
			k++;
			num[k]=s[i]-'0';
		}
	}
	sort(num+1,num+k+1);
	for(int i=k;i>=1;i--)cout<<num[i];
	return 0;
}