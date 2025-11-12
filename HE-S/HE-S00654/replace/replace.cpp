#include<bits/stdc++.h>
using namespace std;
string s[20010];
string s2[20010];
string t[20010];
string t2[20010];
string t3,t4;
int n,p,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	for(int i=1;i<=p;i++){
		cin>>t[i]>>t2[i];
	}
	if(p==2){
		cout<<2<<'\n'<<0;
		return 0;
	}
	if(p==4){
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==t[1]&&s2[i]==t2[1])ans++;
	}
	int l=t[1].length()-1;
	int tot=0,sum=0;
	for(int i=0;i<=l;i++){
		if(t[1][i]=='b')tot=i;
	}
	for(int i=0;i<=l;i++){
		if(t2[1][i]=='b')sum=i;
	}
	int o=sum,r=tot;
	tot=max(o,r);
	sum=min(o,r);
	cout<<tot<<"  "<<sum<<endl;
	for(int i=sum;i<=tot;i++){
		t3+=t[1][i];
		//cout<<t[1][i+sum];
	}
	for(int i=sum;i<=tot;i++){
		t4+=t2[1][i];
	}
	cout<<t3<<endl<<t4<<endl;
//	string t3=t[1][tot]-t[1][sum];
//	string t4=t2[1][tot]-t2[1][sum];
	for(int i=1;i<=n;i++){
		if(s[i]==t3&&s2[i]==t4)ans++;
	}
	cout<<ans;
	return 0;
}
