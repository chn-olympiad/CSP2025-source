#include<bits/stdc++.h>
using namespace std;
long long n,q,s,a,b,x,y;
string s1[200005],s2[200005],t1[200005],t2[2000005];
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
		b=0;
		for(int j=1;j<=n;j++){
			for(int h=1;h<=t1[i].length();h++){
				for(int w=1;w<=s1[j].length();w++){
					if(t1[i][h]==s1[j][w]) s++;
					else s=0;
					if(s==t1[i].length()) b++;
				}
			}
		}
		cout<<b<<endl;
	}
	return 0;
}
