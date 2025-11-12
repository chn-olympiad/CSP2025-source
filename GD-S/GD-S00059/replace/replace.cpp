#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
map<pair<string,string>,int> fin;
int n,q;
string qw,wq;
void nsjh(string a,string b){
	int beg=0,end=a.size()-1;
	for(;;) if(a[beg]!=b[beg]) break;
	else a[beg]='1',beg++;
	for(;;) if(a[end]!=b[end]) break;
	else end--;
	qw.clear();
	wq.clear();
	for(int i=beg;i<=end;i++) qw+=a[i],wq+=b[i];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;cin>>s1>>s2;
		nsjh(s1,s2);
		fin[make_pair(qw,wq)]++;
	}
	for(int i=0;i<q;i++){
		string s1,s2;cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		nsjh(s1,s2);
		cout<<fin[make_pair(qw,wq)]<<endl;
	}
	return 0;
}
