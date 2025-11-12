#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
string s[500005],ki;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int e=2;
	if(k==0){
		ki+='0';
	}
	while(k){//转二进制（反码 
		if(k%e)ki+='1';
		else ki+='0';
		k-=k%e;
		e*=2;
	}
	for(int i=1;i<=n;i++){
		int q=0;
		cin>>q;
		e=2;
		if(q==0)s[i]={'0'};
		while(q){//转二进制（反码 
			if(q%e)s[i]+='1';
			else s[i]+='0';
			q-=q%e;
			e*=2;
		}
		
		if(s[i]==ki)ans++;
	}
	for(int i=1;i<=n;i++){
		if(s[i][0]=='a')continue;
		string bj;
		int fl;
		bool fi=false; 
		for(int j=i+1;j<n;j++){
			bj.erase();
			for(int t=0;t<max(s[i].size(),s[j].size());t++){
				if(s[i][t]==s[j][t])bj+='0';
				else bj+='1';
			}
			if(ki==bj){
				ans++;
				fi=true;
				fl=j;
				break;
			}
		}
		if(fi==true)i=fl+1;
	}
	cout<<ans<<endl;
	return 0;
}
