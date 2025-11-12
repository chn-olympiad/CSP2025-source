#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int ans[1000000];
	long long a=s.size();
	long long b=0;
	for(int i=0;i<=a;i++){
		if((s[i]+'0')%2==0 || (s[i]+'0')%2==1){
			ans[i]=s[i];
			b++;
		}
	}
	for(int i=0;i<b;i++){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=0;i<b;i++){
		cout<<ans[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
