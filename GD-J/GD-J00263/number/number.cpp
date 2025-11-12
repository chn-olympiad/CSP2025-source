#include<bits/stdc++.h>
using namespace std;
const int N=1e6*2+7;
int n,m;
char str[N];
int ans[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout)
	cin>>str;
	n=strlen(str);
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9') ans[++cnt]=str[i]-48;
	}
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<ans[i];
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
