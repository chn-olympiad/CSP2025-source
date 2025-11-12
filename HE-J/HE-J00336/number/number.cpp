#include<bits/stdc++.h>
using namespace std;
int main(){
	int tnt=0;
	int z=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;char r[100010];
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			r[z]=s[i];
			tnt+=1;
			z++;
		}
	}
	for(int i=0;i<tnt;++i){
			for(int j=i;j<tnt;j++){
				if(r[i]<r[j]){
					swap(r[i],r[j]);
				}
			}
	}
	for(int i=0;i<tnt;i++){
		cout<<r[i];
	}
	return 0;
} 
