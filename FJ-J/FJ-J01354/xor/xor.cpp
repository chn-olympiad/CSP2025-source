#include<bits/stdc++.h>
using namespace std;
int n,k,s[512345],ans;
int check1(int x){
	string ans;
	while(x>1){
		ans=char(x%2+'0')+ans;
		x/=2;
	}ans='1'+ans;
	int num=0;
	for(int i=0;i<ans.size();i++){
		if(ans[i]=='1') num=num*10;
		else num=num*10+1;
	}
	return num;
}int check2(int x){
	int num=0;
	for(int i=0;x>0;i++){
		num+=x%10*pow(2,i);
		x/=10;
	}return num;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			num+=check2(s[j]);
			if(num==k){
				ans++;
				i=j;
				break;
			}if(num>k) break;
		}
	}cout<<ans;
	return 0;
}
