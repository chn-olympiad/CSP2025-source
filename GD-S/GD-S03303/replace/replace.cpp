#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[20010],s2[20010];
string t1,t2;
bool check(int a,int b,int c){
	for(int i=0;i<a;i++){
		if(t1[i]!=t2[i]){
			return 0;
		}
	}
	for(int i=a+b,j=a+c;i<t1.size();i++,j++){
		if(t1[i]!=t2[j]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		int summ=0;
		for(int i=1;i<=n;i++){
			int n1=t1.find(s1[i]);
			int n2=t2.find(s2[i]);
			if(n1!=-1&&n2!=-1&&n1==n2&&t1.size()-s1[i].size()+s2[i].size()==t2.size()){
				if(check(n2,s2[i].size(),s1[i].size())){
					summ++;
				}
			}
		}
		cout<<summ<<endl;
	}
	return 0;
}

