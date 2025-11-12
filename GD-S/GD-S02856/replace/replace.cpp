#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	string a[200005],b[200005];
	cin>>n>>q;
		int k=0,sum=0;
		string s1,s2,v1,v2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		while(q--){
			long long sum=0;
			cin>>s1>>s2;
			for(int i=s1.size()-1;i>=0;i--){
				string v1,v2;
				for(int j=i;j<s1.size();j++){
					long long h=0;
					v1+=s1[j],v2+=s2[j];
					for(int ii=0;ii<i;ii++){
						if(s1[ii]!=s2[ii])
						h=1;
						break;
					}
					for(int ii=j+1;ii<s1.size();ii++){
						if(s1[ii]!=s2[ii])
						h=1;
						break;
					}
					if(h)continue;
					for(int k=1;k<=n;k++){
						if(v1==a[k]&&v2==b[k]){
							sum++;
						}
					}
				}
			}
			cout<<sum<<endl;
		}
		return 0;
}
