#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],n=0;
long long t;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			ans[n]=s[i]-48;
			n++;
		}
	}
	for(t=n*2;t>0;t--){
		for(int j=0;j<n;j++){
			if((int(ans[j])>int(ans[j-1]))){
				swap(ans[j],ans[j-1]);
			}
		}
	}
	for(int k=0;k<n;k++){
		cout<<ans[k-1];
	}
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	return 0;
}
