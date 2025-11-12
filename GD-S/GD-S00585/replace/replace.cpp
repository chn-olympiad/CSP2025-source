#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
string s1[200005],s2[200005],t1,t2;
void check(int x,int y){
	if(t1[x]==s1[y][0]){
		for(int i=1;i<s1[y].size();i++){
			if(x+i>=t1.size()||t1[x+i]!=s1[y][i]){
				return;
			}
		}
		for(int i=0;i<x;i++){
			if(t1[i]!=t2[i]){
				return;
			}
		}
		for(int i=x;i<x+s2[y].size();i++){
			if(s2[y][i-x]!=t2[i]){
				return;
			}
		}
		int m=x+s2[y].size()-1;
		for(int i=x+s1[y].size();i<t1.size();i++){
			m++;
			if(t1[i]!=t2[m]){
				return;
			}
			if(i==t1.size()-1&&m!=t2.size()-1){
				return;
			}
		}
		ans++; 
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<t;i++){
		cin>>t1>>t2;
		ans=0;
		for(int j=0;j<t1.size();j++){
			for(int k=0;k<n;k++){
				check(j,k);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
