#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,q,ans;
string s1[200010],s2[200010],t1[200010],t2[200010];
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
	for(int i=1;i<=q;i++){
		ans=0;
	for(int i2=1;i2<=n;i2++){
		for(int j=0;j<t1[i].size();j++){
			int z=j+s1[i2].size()-1;
				bool f=true;
				for(int ii=j,iii=0;ii<=z,iii<s1[i2].size();ii++,iii++){
					if(t1[i][ii]!=s1[i2][iii]){
						f=false;
						break;
					}
					
				}
				if(f){
						for(int ii2=j,iii2=0;ii2<=z,iii2<s2[i2].size();ii2++,iii2++){
							if(t2[i][ii2]!=s2[i2][iii2]){
								f=false;
								break;
							}
						}
						if(f){
							for(int ii3=0;ii3<j;ii3++){
							if(t2[i][ii3]!=t1[i][ii3]){
								f=false;
								break;
							}
							}
							for(int ii3=z+1;ii3<t1[i].size();ii3++){
							if(t2[i][ii3]!=t1[i][ii3]){
								f=false;
								break;
							}
						}
							if(f)
							ans++;
						}
					}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
