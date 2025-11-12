#include<bits/stdc++.h>
using namespace std;
int n,q;
string str1[10001];
string str2[10001];
string s1,s2;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int lt=t1.size();
		for(int i=1;i<=n;i++){
			int a=t1.find(str1[i]);
			int b=str1[i].size();
			char t12[10001];
			string c=str2[i];
			if(a>b+1){
				continue;
			}
			for(int j=0;j<=n;j++){
				if(j<a || j>=a+b){
					t12[j]=t1[j];
				}
				else{
					t12[j]=c[j-a];
				}
			}
			if(i==3){
			}

			if(t2 ==  t12 && a<=lt+1 && a>=0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
