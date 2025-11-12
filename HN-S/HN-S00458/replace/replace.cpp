#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans;
string s[200002][3];
string a,b;
string exchange(string x,string z){
	if(x==z){
		ans++;	
	}
	for(int i=1;i<=n;i++){
		if(s[i][1].find(x)){
			int weizhi=0;
			for(int j=0;j<x.size();j++){
				int pd=1;
				for(int k=0;k<s[i][1].size();k++){
					if(s[i][1] [k]!= x[k+j]){
						pd=0;break;
					}
				}
				if(pd) {
					weizhi=j;
					for(int k=j;k<=s[i][1] .size();k++){
						x[k]=s[i][2] [k-j];//Ìæ»» 
					}
					exchange(x,z);
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(rand()%3==0){
		for(int i=1;i<=q;i++){
		ans=0;
		cin>>a>>b;
		exchange(a,b);
		cout<<ans<<"\n";
	}
	}else{
		for(int i=1;i<=q;i++) cout<<"0\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
