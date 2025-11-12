#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
string s1[2500006],s2[2500006];
string t1,t2;
int la,lb,lj;
ll total;
bool flag,flag2;

int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		la=t1.length();lb=t2.length();

		if(la!=lb){cout<<0<<endl;continue;}

		total=0;
		for(int j=1;j<=n;j++){
			//cout<<"question "<<i<<" checking s"<<j<<endl;
			lj=s1[j].length();
			for(int k=0;k<=la-lj;k++){
				//cout<<"    k is "<<k<<endl;
				flag=1;flag2=1;
				for(int x=0;x<lj;x++){
					if(s1[j][x]!=t1[k+x]||s2[j][x]!=t2[k+x]){flag=0;break;}
				}
				if(flag){
					for(int x=0;x<k;x++){
						if(t1[x]!=t2[x]){flag2=0;break;}
					}
					for(int x=k+lj;x<la;x++){
						if(t1[x]!=t2[x]){flag2=0;break;}
					}
					if(flag2){
						total++;
						//cout<<"replaced at "<<k<<" with "<<s2[j]<<endl;
					}
				}
			}
		}
		cout<<total<<endl;
	}
	return 0;
}
