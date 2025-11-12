#include <bits/stdc++.h>
using namespace std;
const int N=200100,M=998244389;
int n,q;
vector<int> pre1[N],pre2[N];
unordered_
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		pre1[i]=pre2[i]={0};
		char ch='0';
		while(ch<'a'||ch>'z') ch=getchar();
		while('a'<=ch&&ch<='z')
			pre1[i].push_back((pre1[i].back()*29ll+ch-'a'+1)%M),ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		while('a'<=ch&&ch<='z')
			pre2[i].push_back((pre2[i].back()*29ll+ch-'a'+1)%M),ch=getchar();
	}
	for(int i=n+1;q;q--){
		pre1[i]=pre2[i]={0};
		char ch='0';
		while(ch<'a'||ch>'z') ch=getchar();
		while('a'<=ch&&ch<='z')
			pre1[i].push_back((pre1[i].back()*29ll+ch-'a'+1)%M),ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		while('a'<=ch&&ch<='z')
			pre2[i].push_back((pre2[i].back()*29ll+ch-'a'+1)%M),ch=getchar();
		for(int i=1;i<=n;i++)
	}
}
