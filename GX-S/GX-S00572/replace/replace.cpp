#include<bits/stdc++.h>
using namespace std;
string s[200100];
string t[200100];
string x[200100];
string y[200100];
int cmp(string p,string q){
	int l=p.length(),s=q.length();
	for(int i=0;i<l;i++){
		if(p[i]==q[0]){
			bool flag=true;
			for(int j=1;j<s;j++){
				if(q[j]!=p[i+j]){
					flag=false;
					break;
				}
			}
			if(flag)return i;
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){cin>>s[i]>>t[i];}
	for(int i=0;i<q;i++){
		int cnt=0;
		cin>>x[i]>>y[i];
		for(int j=0;j<n;j++){
			if(cmp(x[i],s[j])!=-1){
				string num="";
				for(int k=0;k<cmp(x[i],s[j]);k++)num=num+x[i][k];
				num=num+t[j];
				int l=x[i].length();
				for(int k=cmp(x[i],s[j])+t[j].length();k<l;k++)num=num+x[i][k];
				if(num==y[i]){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
