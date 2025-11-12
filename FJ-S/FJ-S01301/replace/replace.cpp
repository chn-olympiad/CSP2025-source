#include<iostream>
#include<string>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int main(){
	freopen("replace.in","w",stdin);
	freopen("replace.out","r",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int L=-1,R=-1;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				L=j;
				break;
			}
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				R=j;
				break;
			}
		}
		if(L==-1){
			cout<<0<<'\n';
			continue;
		}
		cout<<L<<' '<<R<<'\n';
		for(int j=1;j<=n;j++){
			for(int h=0;h<t1.size()-s1[j].size()+1;h++){
				bool fl1=1;
				int l=h,r=h+s1[j].size()-1;
				for(int k=h;k<h+s1[j].size();k++){
					if(s1[j][k-h]!=t1[k]){
						fl1=0;
						break;
					}
				}
				if(fl1){
					if(L<l||R>r)continue;
					bool fl2=1;
					for(int k=l;k<=r;k++){
						if(s2[j][k-l]!=t2[k]){
							fl2=0;
							break;
						}
					}
					if(fl2)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
