#include<bits/stdc++.h>
using namespace std;
string cha(string a,string& b,string& c){
	int i=0,flag;bool tick=false;
	for(int j=0;j<a.size();j++){
		if(a[j]==b[i]){
			i++;
			if(tick==false)flag=j;
			tick=true;
			if(i==b.size()){
				for(int k=j;k<j+i;k++)a[k]=c[k-j];
				return a;
			}
		}
		else{
			i=0;
			tick=false;
		}
	}
	return a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	vector<string>ns(n*2);
	for(int i=0;i<n;i+=2){
		cin>>ns[i]>>ns[i+1];
	}
	int cnt=0;
	for(int i=0;i<q;i++){
		string str1,str2;
		cin>>str1>>str2;
		for(int i=0;i<ns.size();i+=2){
			if(cha(str1,ns[i],ns[i+1])==str2)cnt++;
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}