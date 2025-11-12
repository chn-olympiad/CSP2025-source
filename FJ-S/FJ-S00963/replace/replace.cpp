#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,q,ans=0;
string t1[N],t2[N];
string s1[N],s2[N];
bool find(int k,int x,int i){ 
	for(int j=0;j<s1[x].size();j++,i++){
		if(t1[k][i]!=s1[x][j])
			return false;
	}
	return true;
}
void replace(int k,int x,int i){
	string t1_1=t1[k];
	for(int j=0;j<s1[x].size();j++,i++){
		t1_1[i]=s2[x][j];
	}	
	if(t1_1==t2[k])
		ans++;
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int k=0;k<q;k++){
		ans=0;
		for(int i=0;i<n;i++){
			if(s1[i]>t1[k]||s2[i]>t2[k]||t1[k].size()!=t2[k].size()){
				break;
			}
			for(int j=0;j<t1[k].size();j++){
				if(t1[k][j]==s1[i][0]&&find(k,i,j))
					replace(k,i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
}
