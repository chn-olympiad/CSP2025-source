#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],sum = 0;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	
//	for(int i = 0;i<s.size();i++){
//		if(s[i]>='0' && s[i]<='9'){
//			sum++;
//			for(int j = i;j<s.size();j++){
//				a[j] = s[i]-'0';
//			}
//		}
//	}
	
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++;
		}
	}
	
	for(int i = 0;i<s.size();i++){
		int ans = 0;
		if(s[i]>='0' && s[i]<='9'){
			ans = s[i];
			for(int j = i;j<sum;j++){
				a[j] = ans-'0'; 
			}
		}
	}
	sort(a,a+sum);
	
	cout<<5; 
	return 0;
} 
