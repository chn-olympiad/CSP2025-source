#include<bits\stdc++.h>
using namespace std;
int strlen(string s){
	for(int i=0;;i++){
		if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))){
			return i;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	string t1,t2;
	string s[1000][2];
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		s[i][1]=t1;s[i][2]=t2;
	}
	while(q--){
		cin>>t1>>t2;
		int l=strlen(t1),l2=strlen(t2);
		long long ans=0;
		if(l!=l2){
			cout<<"0"<<endl;
		}else{
			for(int i=0;i<l;i++){
				for(int j=0;j<n;j++){
					if(t1[i]==s[j][1][0]){
						string t=t1;
						for(int k=0;k<strlen(s[j][1]);k++){
							if(t1[i+k]==s[j][1][k]){
								t[i+k]=s[j][2][k];
							}else{
								k=strlen(s[j][1]);
								j=n;
							}
						}
						if(t==t2){
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
