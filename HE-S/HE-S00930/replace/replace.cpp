#include<bits/stdc++.h>
using namespace std;

int n,q;
const int N=2e5+5;
struct node{
	string ss1,ss2;
}a[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].ss1>>a[i].ss2;
	
	while(q--){
		string s,t;
		cin>>s>>t;
		string ss=s;
		int ans=0;
		for(int i=1;i<=n;i++){
			s=ss;
			int pos=s.find(a[i].ss1);
			if(pos!=-1){
//				cout<<a[i].ss1<<" aaaaaaaaaa"<<endl;
//				cout<<pos<<" pppppppp"<<endl;
				string aa=a[i].ss2;
				int k=0;
				for(int j=pos;j<=pos+a[i].ss1.size()-1;j++){
					s[j]=aa[k];
					k++;
				}
//				cout<<s<<" ssssssss"<<endl;
				if(s==t) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
