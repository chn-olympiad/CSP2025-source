#include<bits/stdc++.h>
using namespace std;
map<int,long long> we;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int j=0,k=s1.size()-1; 
		while(s1[j]==s2[j]){
			j++;
		}
		while(s1[k]==s2[k]){
			k--;
		}
		int e=0;
		for(int q=0;q<=k-j;q++){
			int a1=int(s1[j+q]-'0');
			e=(e*37+a1)%998244353;
		}
		for(int q=0;q<=k-j;q++){
			int a2=int(s2[q+j]-'0');
			e=(e*37+a2)%998244353;
		}
		we[e]++;
		//cout<<ss[i][0]<<' '<<ss[i][1]<<endl;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int j=0,k=s1.size()-1,ans=0; 
		while(s1[j]==s2[j]){
			j++;
		}
		while(s1[k]==s2[k]){
			k--;
		}
		int e=0;
		for(int q=0;q<=k-j;q++){
			int a1=int(s1[j+q]-'0');
			e=(e*37+a1)%998244353;
		}
		for(int q=0;q<=k-j;q++){
			int a2=int(s2[q+j]-'0');
			e=(e*37+a2)%998244353;
		}
		cout<<we[e]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
