#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5,Q=2e5;
string s1[N],s2[N];
string t1[Q],t2[Q];
struct lb{
	int last;
	vector<int> next;
	vector<string> have;
};
vector<lb> hash;
void in_(string *s11,string *s21){
	for(int i=1;i<=n;i++){
		int z1=0;
		for(z1;s2[z1]==s1[z1];z1++);
		if(hash[z1].last!=1)hash[z1].last=1,
			hash[1].next.push_back(i);
		for(int i;;i++){
			string x=s1[i],y=s2[i];
			char x1=x,y1=y;
			z1=x-y;
		}
	}
}
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)cin>>t1[i]>>t1[i];
	return 0;
}
