#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],t1[N],t2[N];
int n,q;
bool tag=true;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n<=1e4){
		for(int k=1;k<=q;k++){
			int cnt=0,flag=1;
			for(int i=1;i<=n;i++){
				if(t1[k].size()<s1[i].size()) continue;
				long long a=t1[k].find(s1[i]),b=t2[k].find(s2[i]);
				if(a<0||b<0||a!=b) continue;
				for(int j=0;j<=a-1;j++){
					if(t1[k][j]!=t2[k][j]){
						flag=0;
						break;
					}
				} 
				for(int j=a+s1[i].size();j<t1[k].size();j++){
					if(t1[k][j]!=t2[k][j]){
						flag=0;
						break;
					}
				}
				cnt+=flag;
			}
			cout<<cnt<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(char j='c';j<='z';j++){
				long long x=s1[i].find(j),y=s2[i].find(j);
				if(x>=0||y>=0){
					tag=false;
					break;
				}
			}
		} 
		for(int i=1;i<=q;i++){
			for(char j='c';j<='z';j++){
				long long x=t1[i].find(j),y=t2[i].find(j);
				if(x>=0||y>=0){
					tag=false;
					break;
				}
			} 
		}
		if(tag==true){
			for(int k=1;k<=q;k++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(t1[k].size()<s1[i].size()) continue;
					long long a=t1[k].find(s1[i]),b=t2[k].find(s2[i]);
					if(a<0||b<0||a!=b) continue;
					cnt++;
				}
				cout<<cnt<<endl;
			}
		}
		else{
			for(int k=1;k<=q;k++){
				int cnt=0,flag=1;
				for(int i=1;i<=n;i++){
					if(t1[k].size()<s1[i].size()) continue;
					long long a=t1[k].find(s1[i]),b=t2[k].find(s2[i]);
					if(a<0||b<0||a!=b) continue;
					for(int j=0;j<=a-1;j++){
						if(t1[k][j]!=t2[k][j]){
							flag=0;
							break;
						}
					} 
					for(int j=a+s1[i].size();j<t1[k].size();j++){
						if(t1[k][j]!=t2[k][j]){
							flag=0;
							break;
						}
					}
					cnt+=flag;
				}
				cout<<cnt<<endl;
			}
		}
	}
	return 0;
}
