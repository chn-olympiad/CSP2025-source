#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	map<string,string>dic;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		dic[a]=b;
	}
	for(int xun=0;xun<q;xun++){
		string que,anser;
		cin>>que>>anser;
		long long num=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				string a="";
				string b="";
				string beg="";
				for(int le=0;le<que.size();le++){
					if(le<=i){
						a+=que[le];
					}
					else if(le<=j){
						b+=que[le];
					}
					else{
						beg+=que[le];
					}
				}
				b=dic[b];
				if(a+b+beg==anser) num++; 
			}
		}
		if(dic[que]==anser) num++;
		cout<<num;
	}
	return 0;
}