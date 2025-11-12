#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#define MAXX 200005
using namespace std;

string s1,s2,in1,in2;
map<string ,string > mapp;
queue<string > q;
string in[MAXX];
int n,qu,ans;
bool flag=true;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>qu;
	for(int i=1;i<=n;i++) {
		cin>>in1>>in2;
		mapp[in1]=in2;
		in[i]=in1;
	}
	for(int i=1;i<=qu;i++){
		ffi:;
		ans=0;
		cin>>s1>>s2;
		while(!q.empty()) q.pop();
		q.push(s1);
		while(!q.empty()){
			string lamp=q.front();
			q.pop();
			int len1=lamp.length();
			for(int i=1;i<=len1;i++){
				for(int j=1;j<=n;j++){
					int lens=in[j].length();
					flag=true;
					for(int k=i;k<=i+lens-1;k++){
						if(lamp[k]!=in[j][k]){
							flag=false;
							break;
						}
					} 
					if(flag){ 
						for(int k=i;k<=i+lens-1;k++){
							lamp[k]=mapp[in[j]][k-i+1];
						} 
						if(lamp==s2) {
							ans++;
							goto ffi;
						}
						q.push(lamp);
					}
				} 
			}
		}
		cout<<ans;
		if(i!=qu) cout<<endl;
	}
	return 0;
}
