#include<bits/stdc++.h>
using namespace std;
string s;
int  a[1000005],sum1,sum2,sum3;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		sum1++;
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[i]=s[i]-'0';
			
			if(s[i]=='0'){
				sum2++;
			}
		}
		else{
			a[i]=0;
			sum3++;
		}
	}
	sort(a,a+sum1);
	for(int i=1;i<=sum1-sum2-sum3;i++){
		cout<<a[sum1-i];
		
	}
	for(int i=1;i<=sum2;i++){
		cout<<0;
	}
	return 0;
} 
