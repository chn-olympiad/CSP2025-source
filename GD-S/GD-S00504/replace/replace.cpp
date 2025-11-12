#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,q;
int len[N];
string s1[N],s2[N];
string t1,t2;
int a1[N],a2[N];
int a3[N],a4[N];
bool bbb[N];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		for(int j=0;j<len[i];j++){
			if(s1[i][j]=='a')a1[i]++;
			else break;
		}
		for(int j=len[i]-1;j>=0;j--){
			if(s1[i][j]=='a')a2[i]++;
			else break;
		}
//		cout<<a1[i]<<' '<<a2[i]<<endl;
		for(int j=0;j<len[i];j++){
			if(s2[i][j]=='a')a3[i]++;
			else break;
		}
		for(int j=len[i]-1;j>=0;j--){
			if(s2[i][j]=='a')a4[i]++;
			else break;
		}
//		cout<<a3[i]<<' '<<a4[i]<<endl;
	}
	while(q--){
		ans=0;
		int aa1=0,aa2=0;
		bool bb=0;
		cin>>t1>>t2;
		int leng=t1.size();
		for(int j=0;j<leng;j++){
			if(t1[j]=='a')aa1++;
			else break;
		}
		if(aa1!=n) bb=1;
		for(int j=leng-1;j>=0;j--){
			if(t1[j]=='a')aa2++;
			else break;
		}
		int aa3=0,aa4=0;
		for(int j=0;j<leng;j++){
			if(t2[j]=='a')aa3++;
			else break;
		}
		for(int j=leng-1;j>=0;j--){
			if(t2[j]=='a')aa4++;
			else break;
			}
		//cout<<aa1<<' '<<aa2<<endl;
		for(int i=1;i<=n;i++){
				if(aa1<=a1[i]&&aa2<=a2[i]){
					if(aa3<=a3[i]&&aa4<=a4[i]){
						ans++;
					}
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}

