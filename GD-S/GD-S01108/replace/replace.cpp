#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string work(string x,int l,int r){
	string s="";
	if(l>r) return "";
	for(int i=l;i<=r;i++){
		s+=x[i];
	}
	return s;
}
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2,x,y,z;
		cin>>t1>>t2;
		ans=0;
		for(int l=0;l<t1.size();l++){
			for(int r=l;r<t1.size();r++){
				x=work(t1,0,l-1);
				y=work(t1,l,r);
				z=work(t1,r+1,t1.size()-1);
//				cout<<l<<" "<<r<<" "<<x+y+z<<"\n";
				for(int i=1;i<=n;i++){
//					cout<<i<<" "<<x+s2[i]+z<<" "<<t2<<"\n";
					if(y==s1[i]&&x+s2[i]+z==t2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";;
	}
	return 0;
}
