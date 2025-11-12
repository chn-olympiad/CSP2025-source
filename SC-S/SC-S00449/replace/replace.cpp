#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;

int m,n;
string a[maxn];
string b[maxn];
string t1;
string t2;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for (int k=1;k<=n;k++){
		long long ans=0;
		cin>>t1>>t2;
		string d1;
		string d2;
		if (t1.length()!=t2.length()){
			cout<<0<<'\n';
			continue;
		}
		int len=t1.length();
		int st=-1,ed=-1;
		for (int i=0;i<=len-1;i++){
			if (t1[i]!=t2[i]){
				st=i;
				break;
			}
		}
		for (int i=len-1;i>=0;i--){
			if (t1[i]!=t2[i]){
				ed=i;
				break;
			}
		}
		for (int i=st;i<=ed;i++){
			d1+=t1[i];
			d2+=t2[i];
		}
		string an[maxn];
		for (int i=1;i<=m;i++){
			if (t1.find(a[i])!=-1&&t2.find(b[i])!=-1&&t1.find(a[i])==t2.find(b[i])){
				if (a[i].find(d1)!=-1&&b[i].find(d2)!=-1){
					bool check=true;
					for (int j=1;j<=ans;j++){
						if (a[i]==an[j]){
							check=false;
							break;
						}
					}
					if (check){
						ans++;
						an[ans]=a[i];
					}
				}
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
