#include<bits/stdc++.h>
using namespace std;
int a[5000005],l[5000005],r[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int k1=s1.find('b');
		int k2=s2.find('b');
		a[i]=k2-k1;
		l[i]=k1;
		r[i]=s1.size()-k1-1;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.size();
		int l2=s2.size();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		long long cnt=0;
		int k1=s1.find('b');
		int k2=s2.find('b');
		for(int j=1;j<=n;j++){
			if(k2-k1==a[j]&&l[j]<=k1&&r[j]<=l1-k1-1){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
