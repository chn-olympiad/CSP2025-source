#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,a[5005],dp[5005],ans;
inline void Ad(int &x,int y){x=(x+y)%md;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++)ans=(ans+dp[j])%md;
		for(int j=5001;j>=0;j--)Ad(dp[min(5001,j+a[i])],dp[j]);
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
string s;
string t;
int id[1005];
bool cmp(char x,char y){
	return id[x]<id[y];
}
string a,b;
void Doa(){
	while(a.size()<5){
		if(!s.size())break;
		random_shuffle(s.begin(),s.end());
		a+=s[0];
		s.erase(s.begin());
	}
	sort(a.begin(),a.end(),cmp);
}
void Dob(){
	while(b.size()<5){
		if(!s.size())break;
		random_shuffle(s.begin(),s.end());
		b+=s[0];
		s.erase(s.begin());
	}
	sort(b.begin(),b.end(),cmp);
}
void ada(){
	for(int i=0;i<t.size();i++){
		while(a[0]!=t[i])random_shuffle(a.begin(),a.end());
		a.erase(a.begin());
	}
}
void adb(){
	for(int i=0;i<t.size();i++){
		while(b[0]!=t[i])random_shuffle(b.begin(),b.end());
		b.erase(b.begin());
	}
}
bool f;
int main(){
	srand(time(0));
	s="7777-+555533332222AAAAKKKKQQQQJJJJ00009999888866664444";
	for(int i=0;i<52;i++)id[s[i]]=i;
	Doa();Dob();
	while(1){
		random_shuffle(s.begin(),s.end());
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		cout<<"Me:"<<a<<"\nOpponent:"<<b<<endl;cout<<s.size()<<" left.\n";
		cin>>t;
		if(t=="no"){
			if(f)Doa(),Dob();
			else Dob(),Doa();
		}
		else if(f)adb();
		else ada();
		f^=1;
	}
	return 0;
}
*/
