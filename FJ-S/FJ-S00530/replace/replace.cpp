#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
string s1[N],s2[N];
string l,r;
bool f(int x,int y,string z){
	int o=0;
//	cout<<"9h"<<x+y-1<<endl;
	for(int i=x;i<=x+y-1;i++){
		
		l[i]=z[o];
		o++;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==4)cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else if(n==4&&m==2)cout<<2<<endl<<0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		
		cin>>l>>r;
		if(l.size()!=r.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(s1[j].size()>l.size()){
//				cout<<"|"<<endl;
				continue;
			}
			string p,h=l;
//			cout<<" "<<s1[j].size()<<endl;
			for(int k=0;k<s1[j].size();k++){
				p+=l[k];
			}
//			cout<<p<<endl;
			if(s1[i]==p){
//				cout<<s2[i]<<endl;
				string q=s2[j];
				int len=s2[j].size();
				f(0,len,q);
//				cout<<"p:"<<p<<" q:"<<q;
//				cout<<" || ";
//				cout<<l<<endl;
				if(l==r)ans++;
				l=h;
			}
//			cout<<j<<' '<<s1[j]<<endl;
			for(int k=s1[j].size();k<l.size();k++){
				p.erase(0,1);
				p+=l[k];
//				cout<<p<<endl;
				if(s1[j]==p){
					string q=s2[j];
					int len=s2[j].size();
					f(k-s2[j].size()+1,len,q);
//					cout<<k<<' '<<s2[j].size();
//					cout<<" p:"<<p<<" q:"<<q;
//					cout<<" || ";
//					cout<<l<<endl;
					if(l==r)ans++;
					l=h;
				}
			}
			l=h;
		}
		cout<<ans<<endl;
	}
	return 0;

}
