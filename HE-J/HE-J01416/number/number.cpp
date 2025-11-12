#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000000],ans[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int c;
	for(int i=0;i<=a.size();i++) n[i]=-1;
	for(int i=0;i<a.size();i++){
		if(a[i]==48) n[i]=0;
		if(a[i]==49) n[i]=1;
		if(a[i]==50) n[i]=2;
		if(a[i]==51) n[i]=3;
		if(a[i]==52) n[i]=4;
		if(a[i]==53) n[i]=5;
		if(a[i]==54) n[i]=6;
		if(a[i]==55) n[i]=7;
		if(a[i]==56) n[i]=8;
		if(a[i]==57) n[i]=9;
	}
	for(int i=0;i<a.size();i++){
		int maxn=0;
		for(int j=0;j<a.size();j++){
			if(n[j]>n[maxn]){
				maxn=j;
			}
		}
		ans[i]=n[maxn];
		n[maxn]=-1;
	}
	for(int i=0;i<a.size();i++){
		if(ans[i]==-1)continue;
		cout<<ans[i];
	} 
	return 0;
}
