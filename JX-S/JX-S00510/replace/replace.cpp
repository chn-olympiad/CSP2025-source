#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,q,ans,www[10000010];
string x,y,z[N];
bool flag;
struct zzz{
	string s1,s2;
}a[N];
bool cmp(zzz i,zzz j){
	return i.s1.size()<j.s1.size();
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		ll n1=a[i].s1.size(),cnt=0;
		for(int j=0;j<n1;j++){
			if(a[i].s1[j]!='a'&&a[i].s1[j]!='b'){
				flag=1;
			}
			if(a[i].s1[j]=='b') cnt++;
		}
		if(cnt!=1) flag=1;
		n1=a[i].s2.size(),cnt=0;
		for(int j=0;j<n1;j++){
			if(a[i].s2[j]!='a'&&a[i].s2[j]!='b'){
				flag=1;
			}
			if(a[i].s2[j]=='b') cnt++;
		}
		if(cnt!=1) flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			ll n1=a[i].s1.size(),num1,num2;
			for(int j=0;j<n1;j++){
				if(a[j].s1[j]=='b'){
					num1=i;
					break;
				}
			}
			n1=a[i].s2.size();
			for(int j=0;j<n1;j++){
				if(a[i].s2[j]=='b'){
					num2=j;
					break;
				}
			}
			www[num1-num2+5000000]++;
		}
		while(q--){
			cin>>x>>y;
			if(x.size()!=y.size()){
				cout<<0<<endl;
				continue;
			}
			ll n1=x.size(),num1,num2;
			for(int i=0;i<n1;i++){
				if(x[i]=='b'){
					num1=i;
					break;
				}
			}
			n1=y.size();
			for(int i=0;i<n1;i++){
				if(y[i]=='b'){
					num2=i;
					break;
				}
			}
			cout<<www[num1-num2+5000000]<<endl;
		}
	}
	else{
		while(q--){
			cin>>x>>y;
			if(x.size()!=y.size()){
				cout<<0<<endl;
				continue;
			}
			ll n1=x.size(),ans=0;
			z[n1]="";
			for(int i=n1-1;i>=1;i--){
				z[i]=x[i]+z[i+1];
			}
			string h="";
			for(int i=0;i<n1;i++){
				string s="";
				for(int j=i;j<n1;j++){
					s+=x[j];
					for(int k=1;k<=n;k++){
						if(a[k].s1.size()>s.size()) continue;
						if(a[k].s1==s&&h+a[k].s2+z[j+1]==y) ans++;
					}
				}
				h+=x[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
