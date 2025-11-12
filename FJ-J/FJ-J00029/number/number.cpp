#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    long long k=0;
    long long l=s.size();
    for(long long i=0;i<l;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		ans[k]=s[i]-'0';
    		k++;
		}
	}
	//cout<<k<<endl;
	sort(ans,ans+k+1);
	for(long long i=k;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
