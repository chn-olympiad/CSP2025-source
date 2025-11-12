#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	vector<string>s1(n+1),s2(n+1);
	map<string,int>mp1,mp2;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		mp1[s1[i]]++,mp2[s2[i]]++;
	}
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		int ans=0;
		string a="",b="",c="",d="";
		for(int i=0;i<t1.size();i++){
			string s,t;
			if(i>0) a+=t1[i-1],c+=t2[i-1];
			for(int j=i;j<t1.size();j++){
				s+=t1[j];
				t+=t2[j];
				if(mp1[s]!=0&&mp2[t]!=0){
					for(int k=j+1;k<t1.size();k++) b+=t1[k],d+=t2[k];
					string e=a+t+b,f=c+t+d;
					if(e==f) ans++;
					b="",d="";
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

