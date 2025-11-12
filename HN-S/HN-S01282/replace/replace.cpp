#include<bits/stdc++.h>
using namespace std;
int n,q,len,b,e,sum;
string s1,s2,ls1,ls2;
map<string,string> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		sum=0;
		len=s1.size();
		b=0,e=0;
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				b=j;
				break;
			}
		}
		for(int j=b+1;j<len;j++){
			if(s1[j]!=s2[j]){
				e=j;
			}
		}
		for(int h=0;h<=b;h++){
			for(int t=e;t<len;t++){
				ls1=s1.substr(h,t-h+1);
				ls2=s2.substr(h,t-h+1);
				if(m[ls1]==ls2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
