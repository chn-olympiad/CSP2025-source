#include<bits/stdc++.h>
using namespace std;
int n,q;
int cnt=0;
string a,a1[10],a2[10],s,s1,s2,x,y,z;
bool isin(string xx,string yy){
	int lyy=yy.size();
	int f=0;
	for(int i=0;i<xx.size();i++){
		f=0;
		for(int j=0;j<lyy;j++){
			if(xx[i+j]!=yy[j])f=1;
		}
		if(f==0)return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i];
		}
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			if(isin(s1,a1[i]) && isin(s2,a2[i])){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i];
		}
		while(q--){
			cin>>s1>>s2;
			for(int i=1;i<=n;i++){
				if(isin(s1,a1[i]) && isin(s2,a2[i])){
					cnt++;
				}
			}
			cout<<cnt;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
