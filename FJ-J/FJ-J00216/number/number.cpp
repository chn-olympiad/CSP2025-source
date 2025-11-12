#include<bits/stdc++.h>

using namespace std;

int n,sum=0;
int ans[1000006];
string s;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	ans[0]=-1;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			ans[i]=s[i]-'0',sum++;
	}			
	sort(ans,ans+n,cmp);
	if(ans[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<sum;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
