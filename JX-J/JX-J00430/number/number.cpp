#include<bits/stdc++.h>
using namespace std;
int num[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.length();
	int ln=0;
	for(int i=1;i<=9;i++){
        for(int j=0;j<l;j++){
            if(s[j]-'0'==i) num[i]++;
        }
        ln+=num[i];
	}
	long long ans=0;
	for(int i=9;i>=1;i--){
        while(num[i]!=0){
            ans+=i*pow(10,ln-1);
            ln--;
            num[i]--;
        }
	}
	cout<<ans;
	return 0;
}

