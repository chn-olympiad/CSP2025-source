#include<bits/stdc++.h>
using namespace std;
const long long mumm=131,mod=998244353;
int n,q;
long long memq1;
string s1,s2,t1,t2;
unordered_map<long long,long long>mapo;
struct node{
	string qian,mid,hou;
	int lqian,lhou;
	int hushqian,hushhou,hushmid;
}e[200005];
long long phHush(string s)
{
	long long ans=0;
	for(int i=0;i<s.size();i++)
		ans=(ans*mumm+s[i]-'a')%mod;
	return ans;
}
void PacoHush(int l,int r)
{
	long long ans=0;
	for(int i=l;i<=r;i++)
	{
		ans=(ans*mumm+s1[i]-'a')%mod;
		//ans2=(ans2*131+s2[i]-'a')%mod;
	}
	for(int i=l;i<=r;i++)
	{
		ans=(ans*mumm+s2[i]-'a')%mod;
	}
	if(mapo.count(ans))
	{
		mapo[ans]++;
	}
	else{
		mapo[ans]=1;
	}
	//cout<<ans<<" r"<<endl;
}
long long PacoCal(int l,int r)
{
	long long ans=0;
	for(int i=l;i<=r;i++)
	{
		ans=(ans*mumm+t1[i]-'a')%mod;
		//ans2=(ans2*131+t2[i]-'a')%mod;
	}
	for(int i=l;i<=r;i++)
	{
		ans=(ans*mumm+t2[i]-'a')%mod;
		//ans2=(ans2*131+t2[i]-'a')%mod;
	}
	if(mapo.count(ans))return mapo[ans];
	else return 0ll;
	memq1=ans;
	//cout<<ans<<" w"<<endl;
}
void Paco50()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		e[i].lqian=e[i].lhou=0;
		e[i].qian="";
		e[i].hou="";
		e[i].mid="";
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
			e[i].qian=e[i].qian+s1[j];
			e[i].lqian++;
		}
		for(int j=s1.size()-1;j>=0;j--)
		{
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
			e[i].hou=s1[j]+e[i].hou;
			e[i].lhou++;
		}
		for(int j=l;j<=r;j++)
		{
			e[i].mid=e[i].mid+s1[j];
		}
		for(int j=l;j<=r;j++)
		{
			e[i].mid=e[i].mid+s2[j];
		}
		e[i].hushhou=phHush(e[i].hou);
		e[i].hushqian=phHush(e[i].qian);
		e[i].hushmid=phHush(e[i].mid);
		PacoHush(l,r);
	}
	cin>>t1>>t2;
	if(t1.size()!=t2.size())
	{
		cout<<0<<'\n';
		return ;
	}
	int l=0,r=t1.size()-1;
	for(int i=0;i<t1.size();i++){
		if(t1[i]!=t2[i]){
			l=i;
			break;
		}
	}
	for(int i=t1.size()-1;i>=0;i--)
	{
		if(t1[i]!=t2[i]){
			r=i;
			break;
		}
	}
	int ans=PacoCal(l,r);
	for(int i=1;i<=n;i++)
	{
		//cout<<e[i].qian<<' '<<e[i].hou<<' '<<e[i].mid<<' '<<e[i].hushqian<<' '<<e[i].hushmid<<' '<<e[i].hushhou<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//if(q==1)
	//{
	//	Paco50();
	//	return 0;
	//}
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
			//qian=qian+s1[i];
		}
		for(int j=s1.size()-1;j>=0;j--)
		{
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		PacoHush(0,s1.size()-1);
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=t1.size()-1;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--)
		{
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=0;i<=l;i++)
			for(int j=r;j<=t1.size()-1;j++)
				ans+=PacoCal(i,j);
		cout<<ans<<'\n';
	} 	
	return 0;
}
