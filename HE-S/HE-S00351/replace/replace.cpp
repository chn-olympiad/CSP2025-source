#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
struct node{
	string s1,s2;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2,p1,p2;
		cin>>t1>>t2;
		int l=0,r=0,l1=t1.size();
		ll ans=0;
		while(l<l1){
			p1="";
			p2="";
			if(r==l1){
				l++;
				r=l;
			}
			if(l==l1){
				break;
			}
			for(int j=l;j<=r;j++){
				p1+=t1[j];
				p2+=t2[j];
			}
			for(int j=1;j<=n;j++){
				if(a[j].s1==p1&&a[j].s2==p2){
					ans++;
				}
			}
			r++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
