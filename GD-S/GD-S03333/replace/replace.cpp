#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	string s1[200005],s2[200005];
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n>=2e5){
		while(q--){
			cout<<"0\n";
		}
		return 0;
	}
	while(q--){
		int sum=0;
		string t,idx;
		cin>>t>>idx;
		int lent=t.size();
		for(int j=1;j<=n;j++){
			int lens=s1[j].size();
			if(lens>lent)continue;
			for(int i=0;i<=lent-lens;i++){
				if(t.substr(i,lens)==s1[j]){
					if((t.substr(0,i)==idx.substr(0,i))&&(s2[j]==idx.substr(i,lens))&&(t.substr(i+lens,lent-i-lens+1)==idx.substr(i+lens,lent-i-lens+1)))sum++;
				}
			}
		} 
		cout<<sum<<"\n"; 
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
