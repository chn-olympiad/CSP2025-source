#include <iostream>
using namespace std;
pair<string,string>a[200010];
pair<int,int>ak[200010];
string st(int l,int r,string s){
	string t="";
	for(int i=l;i<r;i++)
		t+=s[i];
	return t;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool p=true;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=make_pair(s1,s2);
		if(!p)
			continue;
		int na=0,nb=0,wa=0,wb=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				if(na==0){
					na++;
					wa=j;
				}
				else{
					p=false;
					break;
				}
			}
			else{
				if(s1[j]!='a'){
					p=false;
					break;
				}
			}
			if(s2[j]=='b'){
				if(nb==0){
					nb++;
					wb=j;
				}
				else{
					p=false;
					break;
				}
			}
			else{
				if(s2[j]!='a'){
					p=false;
					break;
				}
			}
		}
		ak[i]=make_pair(wa,wb);
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int res=0,na=0,nb=0,qa=0,qb=0;
		if(q){for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				if(na==0){
					na++;
					qa=j;
				}
				else{
					p=false;
					break;
				}
			}
			else{
				if(s1[j]!='a'){
					p=false;
					break;
				}
			}
			if(s2[j]=='b'){
				if(nb==0){
					nb++;
					qb=j;
				}
				else{
					p=false;
					break;
				}
			}
			else{
				if(s2[j]!='a'){
					p=false;
					break;
				}
			}
		}}
		for(int j=1;j<=n;j++){
			int sub=a[j].first.size();
			if(sub>s1.size())
				continue;
			if(p){
				if(ak[j].first-ak[j].second==qa-qb)
					res++;
				continue;
			}
			for(int k=0;k<=s1.size()-sub;k++){
				if(st(k,k+sub,s1)==a[j].first&&st(k,k+sub,s2)==a[j].second&&st(0,k,s1)==st(0,k,s2)&&st(k+sub,s1.size(),s1)==st(k+sub,s2.size(),s2)){
					res++;
					break;
				}
			}
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
