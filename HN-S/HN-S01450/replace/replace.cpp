#include<bits/stdc++.h>
using namespace std;
int p[200010],l[200010],pp[200010],ll[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s;
		cin>>s>>s1;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				p[i]=j;
				l[i]=s.size()-j-1;
				break;
			}
		}
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				pp[i]=j;
				ll[i]=s1.size()-j-1;
				break;
			}
		}
	}
	while(q--){
		string a,b;
		int p1,l1,p2,l2;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(a[i]=='b'){
				p1=i; 
				l1=a.size()-i-1;
				break;
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='b'){
				p2=i; 
				l2=b.size()-i-1;
				break;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(p[i]<=p1&&l[i]<=l1){
				if(p1-p[i]+pp[i]==p2&&l1-l[i]+ll[i]==l2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
