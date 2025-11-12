#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+114;

int ans[N];

bool cmp(int q,int p) {
	return q>p;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	
	string s;
	cin>>s;
	int n=s.size(),k=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[++k]=s[i]-'0';
		}
	}
	sort(ans+1,ans+k+1,cmp);
	//if(ans[1]==0) cout<<0;//前导零是个坏东西 
	 
	for(int i=1;i<=k;i++) cout<<ans[i];
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	
	return 0;
} 
