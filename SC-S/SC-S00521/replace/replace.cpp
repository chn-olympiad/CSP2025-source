#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string m[N],n[N];
int t[N];
int flag[N],flag1[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int h,q,all=0;
	cin>>h>>q;
	for(int i=0;i<h;i++){
		cin>>m[i]>>n[i];
		for(int j=0;j<m[i].size();j++){
			if(m[i][j]=='b')flag[i]=j;
			if(n[i][j]=='b') flag1[i]=j;
		}
		t[i]=flag1[i]-flag[i];
	} 
	for(int i=1;i<=q;i++){
		all=0;
		string l,k;
		int ji,ji1;
		cin>>l>>k;
		for(int j=0;j<l.size();j++){
			if(l[j]=='b'){
				ji=j;
			}
			if(k[j]=='b'){
				ji1=j;
			}
		}
		for(int j=0;j<h;j++){
			if(ji1-ji==t[j]&&flag[j]<=ji&&flag1[j]<=ji1){
				all++;
			}
		}
		cout<<all<<endl;
	}
	return 0;
}