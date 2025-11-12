#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s1[MAXN],s2[MAXN];
//int nex[MAXN];
//bool KMP(string x,string y){
//	int l1=x.length(),l2=y.length();
//	nex[0]=-1;
//	int j=-1;
//	for(int i=1;i<l1;i++){
//		while(j!=-1&&x[i]!=x[j]) j=nex[j];
//		if(x[i]==x[j+1]) j++;
//		nex[i]=j+1;
////		cout<<nex[i]<;
//	}
//	j=-1;
//	for(int i=0;i<l2;i++){
//		while(j!=-1&&x[i]!=x[j]) j=nex[j];
//		if(x[i]==x[j+1]) j++;
//		if(j+1==l2) return true;
//		cout<<j<<endl;
//		
//	}
//	return false;
//}
int main(){
//	cout<<("aba"=="aba");
//	return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;int ans=0;
		if(n<=100&&q<=100&&t1.length()<=200&&t2.length()<=200){
			if(t1.length()!=t2.length()){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				for(int l=0;l<t1.length()-s1[i].length()+1;l++){
	//					int r=l+s[i].length()-1,r2=l2+s[i].length()-1;
					bool flag=true;
					for(int k=0;k<l;k++)
						if(t1[k]!=t2[k]){
							flag=false;
							break;
						}
					if(!flag) continue;
					for(int k=l+s1[i].length();k<t1.length();k++)
						if(t1[k]!=t2[k]){
							flag=false;
							break;
						}
					if(!flag) continue;
					for(int k=l;k<l+s1[i].length();k++)
						if(t1[k]!=s1[i][k-l]||t2[k]!=s2[i][k-l]){
							flag=false;
							break;
						}
					if(!flag) continue;
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*


*/
