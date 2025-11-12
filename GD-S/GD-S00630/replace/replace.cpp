#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string q1,q2;
struct node{
	string s1,s2;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=m;i++){
		cin>>q1>>q2;
		ans=0;
		int l=0,r=q1.size()-1;
		while(l<=r){
			string s,sl,sr;
			s=sl=sr="";
			for(int j=0;j<l;j++){
				sl+=q1[j];
			}
			for(int j=l;j<=r;j++){
				s+=q1[j];
			}
			for(int j=r+1;j<int(q1.size());j++){
				sr+=q1[j];
			}
			for(int j=1;j<=n;j++){
				if(s==a[j].s1){
					string ss=sl+a[j].s2+sr;
//					cout<<l<<' '<<ss<<' '<<q2<<' '<<r<<endl;
					if(ss==q2){
						ans++;
					}
				}
			}
			l++;
			s=sl=sr="";
			for(int j=0;j<l;j++){
				sl+=q1[j];
			}
			for(int j=l;j<=r;j++){
				s+=q1[j];
			}
			for(int j=r+1;j<int(q1.size());j++){
				sr+=q1[j];
			}
			for(int j=1;j<=n;j++){
				if(s==a[j].s1){
					string ss=sl+a[j].s2+sr;
//					cout<<ss<<' '<<q2<<endl;
					if(ss==q2){
						ans++;
					}
				}
			}
			l--;
			r--;
			s=sl=sr="";
			for(int j=0;j<l;j++){
				sl+=q1[j];
			}
			for(int j=l;j<=r;j++){
				s+=q1[j];
			}
			for(int j=r+1;j<int(q1.size());j++){
				sr+=q1[j];
			}
			for(int j=1;j<=n;j++){
				if(s==a[j].s1){
					string ss=sl+a[j].s2+sr;
//					cout<<l<<' '<<ss<<' '<<q2<<' '<<r<<endl;
					if(ss==q2){
						ans++;
					}
				}
			}
			l++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
