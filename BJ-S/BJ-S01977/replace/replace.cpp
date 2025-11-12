#include<iostream>
#include<algorithm>
using namespace std;
string sc1[200010],sc2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int s1len=s1.length();
		int fro=0,ba=0;
		for(int j=0;j<s1len;j++){
			if(s1[j]!=s2[j]){
				fro=j;
				break;
			}
		}
		for(int j=s1len-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				ba=j;
				break;
			}
		}
		for(int j=fro;j<=ba;j++){
			sc1[i]+=s1[j];
			sc2[i]+=s2[j];
		}
	}
	for(int i=1;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		int s1len=s1.length(),s2len=s2.length();
		if(s1len!=s2len){
			cout<<"0\n";
		}
		int fro=0,ba=0;
		for(int i=0;i<s1len;i++){
			if(s1[i]!=s2[i]){
				fro=i;
				break;
			}
		}
		for(int i=s1len-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				ba=i;
				break;
			}
		}
		//cout<<fro<<" "<<ba<<endl;
		int len3=ba-fro+1;
		for(int i=1;i<=n;i++){
			int flag=0;
			if((int)sc1[i].length()==len3){
				flag=1;
				for(int j=0;j<len3;j++){
                    //cout<<sc1[i][j]<<" "<<s1[j+fro]<<" "<<sc2[i][j]<<" "<<s2[j+fro];
					if(sc1[i][j]!=s1[j+fro]||sc2[i][j]!=s2[j+fro]){
						flag=0;
						break;
					}
				}
			}
			ans+=flag;
		}
		cout<<ans<<"\n";
	}
}
