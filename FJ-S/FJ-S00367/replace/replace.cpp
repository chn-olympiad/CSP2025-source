#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,q,ans;
string s;
struct node{
	string st,str;
}a[MAXN];
int main(){
//	just Æ­·Ö 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].st>>a[i].str;
	while(q--){
		bool replaced=false;
		ans=0;
		string t,tr;
		cin>>t>>tr;
		if(t.size()!=tr.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
//			if(replaced==true){
//				cout<<ans<<endl;
//				break;
//			}	
			for(int j=0;j<t.size();j++){
				s=t;
				bool f=true,fl=true;
				for(int k=0;k<a[i].st.size();k++){
					if(t[j+k]!=a[i].st[k]){
//						cout<<"´íÎó£º"<<i<<" "<<j+k<<" "<<t[j+k]<<" "<<k<<" "<<a[i].st[k]<<endl;
						f=false;
						break;
					}
				}
				if(f==true){
//					cout<<i<<endl;
					for(int k=0;k<a[i].st.size();k++) s[j+k]=a[i].str[k];
//					for(int k=0;k<a[i].st.size();k++) cout<<a[i].str[k]
//					replaced=true;
//					for(int k=0;k<tr.size();k++) cout<<tr[k];
//					cout<<endl;
//					for(int k=0;k<tr.size();k++) cout<<s[k];
//					cout<<endl;
					for(int k=0;k<tr.size();k++){
						if(s[k]!=tr[k]){
//							cout<<i<<" "<<"err:"<<k<<" "<<s[k]<<" "<<tr[k]<<endl;
							fl=false;
							break;
						}
					}
					if(fl==true){
//						cout<<i<<" "<<j<<endl;
//						for(int k=0;k<tr.size();k++) cout<<tr[k];
//						cout<<endl;
//						for(int k=0;k<tr.size();k++) cout<<t[k];
//						cout<<endl;
						ans++;
						break;	
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

