#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	string s[n],ss[n];
	string t[q],tt[q];
	for(int i=0;i<n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=0;i<q;i++){
		cin>>t[i]>>tt[i];
	}
	int sum=0;
	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			if(t[i].find(s[j])!=-1){
				if(tt[i].find(ss[j])!=-1){
					string ttt=t[i];
					ttt.replace(t[i].find(s[j]),s[j].size(),ss[j]);
					if(ttt==tt[i]){
						sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
