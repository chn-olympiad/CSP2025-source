#include<bits/stdc++.h>
using namespace std;
int ans=0;
const int MAXN=2*1e5;
struct node{
	string x,y;
}ss1[MAXN];
struct no{
	string x,y;
}ss2[MAXN];
int o[MAXN]={0},p=0;
void cmp(no s1,node s2){
	for(int i=0;i<s1.x.size();i++){
		if(s1.x[i]==s2.x[0]){
			int j=0;
			int k=i;
			while(s2.x[k]==s1.x[j]&&j<s2.x.size()){
				k++;
				j++;
			}
			int t=0;
			if(j==s2.x.size()-1){
				for(int l=i;l<=j;l++){
					s1.x[l]=s2.y[t++];
				}
			}
		}
		if(s1.x==s1.y) ans++;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss1[i].x>>ss1[i].y;
		for(int i=0;i<ss1[i].x.size();i++){
			if(ss1[i].x[i]=='b'){
				o[p++]=i;
				break;
			}
		}
		for(int i=0;i<ss1[i].x.size();i++){
			if(ss1[i].y[i]=='b'){
				o[p++]=i;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ss2[i].x>>ss2[i].y;
		if(ss2[i].x.size()!=ss2[i].y.size()){
			cout<<0;
			continue;
		}
		ans=0;
		int h=0;
		for(int j=0;j<ss2[i].x.size();j++){
			if(ss2[i].x[j]=='b') h++;
		}
		int k=0,l=0;
		if(h==1){
			for(int j=0;j<ss2[i].x.size();j++){
				if(ss2[i].x[j]=='b'){
					k=j;
				}
			}
			for(int j=0;j<ss2[i].y.size();j++){
				if(ss2[i].y[j]=='b'){
					l=j;
				}
			}
			for(int i=1;i<=n;i++){
				if(o[2*i-2]-o[2*i-1]==k-l) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			cmp(ss2[i],ss1[j]);
		}
		cout<<ans<<endl;
	}
}
