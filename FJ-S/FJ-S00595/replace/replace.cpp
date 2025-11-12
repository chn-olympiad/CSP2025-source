#include<iostream>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		int s=0;
		for(int j=0;j<n;j++){
			if(t1.find(s1[j])!=-1&&t1.size()==t2.size()){
				string t3=t1;
				bool f=1;
				for(int k=0;k<t1.size();k++) if(t2[k]!=t3[k]&&(k<t1.find(s1[j])||t2[k]!=s2[j][k-t1.find(s1[j])])) f=0;
				if(f) s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
