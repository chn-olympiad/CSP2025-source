#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);
	string s1[a],s2[a];
	string s3,s4;
	for(int i=0;i<a;i++){
		cin>>s1[i]>>s2[i];
	}cout<<1<<endl;
	for(int i=0;i<b;i++){
		cin>>s3>>s4;
		if(s3.length()!=s4.length()){
			printf("%d\n",0);
			continue;
		}
		int ans=0;
		for(int j=0;j<a;j++){
			int d=s3.find(s1[j]);
			if(d!=int(string::npos)){
				string s=s3;
				s=s.substr(0,d)+s2[j]+s.substr(d+s2[j].length(),s.length()-d-s2[j].length());
				if(s==s4)ans++;
				//cout<<s3<<" -> "<<s<<" -- "<<d<<' '<<d+s2[j].length()-(d!=0)<<endl;
			}
		}printf("%d\n",ans);
	}
	return 0;
}
