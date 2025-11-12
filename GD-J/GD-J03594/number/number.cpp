#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=-1;
long long ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=(s.length()-1);i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			cnt++;
			a[cnt]=int(s[i])-48;
			
		}
	}
	sort(a,a+cnt+1);
	for(int i=cnt;i>=0;i--){
		if(a[i]!=0){
			ans*=10;
			ans+=a[i];
		}
		else ans*=10;
	}
	cout<<ans<<endl;
	return 0;
}
