#include<bits/stdc++.h>//RP++
using namespace std;//RP++
int t[11];//RP++
string s;//RP++
int main(){//RP++
	freopen("number.in","r",stdin);//RP++
	freopen("number.out","w",stdout);//RP++
	cin>>s;//RP++
	int n=s.size();//RP++
	for(int i=0;i<n;i++){//RP++
		if('0'<=s[i]&&'9'>=s[i])//RP++
			t[s[i]-'0']++;//RP++
	}//RP++
	for(int i=9;i>=0;i--){//RP++
		while(t[i]>0){//RP++
			t[i]--;//RP++
			cout<<i;//RP++
		}//RP++
	}//RP++
	return 0;//RP++
} //RP++
