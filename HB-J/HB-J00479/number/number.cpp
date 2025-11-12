#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],sum,ans,sum1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sum1=s.size();
	for(int i=0;i<sum1;i++){
		if(s[i]>='a'&&s[i]<='z'){
			continue;
			}else{
				a[i]=s[i]-'0';
				sum++;
			}
		}
	sort(a,a+sum+1);
	for(int i=sum;i>=1;i--){
		ans=ans*10;
		ans+=a[i];
	}
	cout<<ans;
	return 0;
	}
	
