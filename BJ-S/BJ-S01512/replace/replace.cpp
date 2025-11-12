#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,q;
string s1[N],s2[N];
bool rplce(int bgn,int x,string a,string b){
	string ans;
	int l=s1[x].length(),ll=a.length();
	for(int i=0;i<bgn;i++){
		ans+=a[i];
		if(ans[i]!=b[i]) return false;
	}
	for(int i=0;i<l;i++){
		ans+=s2[x][i];
		if(ans[i+bgn]!=b[i+bgn]) return false;
	}
	for(int i=bgn+l;i<ll;i++){
		ans+=a[i];
		if(ans[i]!=b[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			int bgn=t1.find(s1[j]);
			if(bgn==-1) continue;
			else{
				int l=t1.length(),ll=s1[j].length();
				string lst=t1;
				while(bgn>=0){
					string temp;
					ans+=rplce(bgn,j,t1,t2);
					for(int k=0;k<bgn;k++) temp+=lst[k];
					for(int k=bgn;k<bgn+ll;k++) temp+='#';
					for(int k=bgn+ll;k<l;k++) temp+=t1[k];
					lst=temp;
					bgn=temp.find(s1[j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

