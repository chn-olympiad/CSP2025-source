#include<bits/stdc++.h>
using namespace std;
int n,q1,ji[200000];
string s1[100001],s2[100001],t1,t2,kong;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q1;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q1;i++){
		cin>>t1>>t2;}
		/*for(int j=0;j<t1.size();j++){
			for(int h=j;h<t1.size();h++){
				string c=t1,c2=kong;
				for(int f=j;f<=h;f++){
					c2+=t1[i];
				}
				for(int f=0;f<n;f++){
					if(c2==s1[f]){
						for(int m=j;m<=h;m++){
							c[m]=s2[f][m-j];
						}
					}
				}
				if(c==t2){
					ji[i]+=1;
				}
			}
		}
	}*/
	for(int i=0;i<q1;i++){
		cout<<ji[i]+1<<endl;
	}
	return 0;
}
