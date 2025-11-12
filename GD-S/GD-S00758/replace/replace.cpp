#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],s3,s4;
string op(string s,int i,int j,int num){
	for(int k=i,q=0;k<i+j;k++,q++){
		s[k]=s2[num][q];
	}
	return s;
}
bool rep(string s,int j){
	int x=int(s.find(s1[j]));
	string sx=op(s,x,s1[j].length(),j);
	if(sx.find(s4)==0) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s3>>s4;
		for(int j=1;j<=n;j++){
			if(int(s3.find(s1[j]))>=0){
				if(rep(s3,j)) ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

