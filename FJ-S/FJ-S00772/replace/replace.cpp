#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[10001],s2[10001];
string x,y;
int dali25_daji01(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s1[i]==x&&s2[i]==y) ans++;
		else if(x.find(s1[i])!=-1){
			string z=x;
			for(int j=x.find(s1[i]); ;j++){
				if(s1[i][j]==' ') break;
				z[i]=s2[i][j];
			}
			if(z==y) ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
        s1[i]+=' ';s2[i]+=' ';
	}
	while(q--){
		cin>>x>>y;
		cout<<dali25_daji01()<<endl;
	}
	return 0;
}