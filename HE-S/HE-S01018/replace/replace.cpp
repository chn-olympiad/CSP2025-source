#include<bits/stdc++.h>
using namespace std;
struct p{
	string s1,s2;
}sh[200001];
struct qu{
	string c1,c2;
}ch[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,sum=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sh[i].s1>>sh[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>ch[i].c1>>ch[i].c2;
	}
	for(int i=1;i<=q;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if((ch[i].c1.find(sh[j].s1))&&(ch[i].c2.find(sh[j].s2))){
				sum++;
			}
		}
		cout<<sum<<' ';
	}
} 
