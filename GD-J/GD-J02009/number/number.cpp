#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
string s;
LL k,ans[N];
bool cmp(LL x,LL y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL l=s.size();
	for(LL i=0;i<l;i++){
		if(s[i]=='0'){
			ans[++k]=0;
		}
		else if(s[i]=='1'){
			ans[++k]=1;
		}
		else if(s[i]=='2'){
			ans[++k]=2;
		}
		else if(s[i]=='3'){
			ans[++k]=3;
		}
		else if(s[i]=='4'){
			ans[++k]=4;
		}
		else if(s[i]=='5'){
			ans[++k]=5;
		}
		else if(s[i]=='6'){
			ans[++k]=6;
		}
		else if(s[i]=='7'){
			ans[++k]=7;
		}
		else if(s[i]=='8'){
			ans[++k]=8;
		}
		else if(s[i]=='9'){
			ans[++k]=9;
		}
	}
	sort(ans+1,ans+k+1,cmp);
	for(int i=1;i<=k;i++)cout<<ans[i];
	return 0;
} 
