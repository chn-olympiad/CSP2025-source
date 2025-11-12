#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
mt19937 rng(time(0));
int n,q;
unsigned long long num[30];
string a,b;
struct node{
	unsigned long long sum,cnt;
}w[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=28;i++){
		num[i]=rng()%1000000000;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<a.size();j++){
			w[i].sum+=num[a[j]-'a'+1];
		}
		for(int j=0;j<b.size();j++){
			w[i].cnt+=num[b[j]-'a'+1];
		}
	}
	while(q--){
		cin>>a>>b;
		unsigned long long c=0,d=0;
		for(int i=0;i<a.size();i++){
			c+=num[a[i]-'a'+1];
		}
		for(int i=0;i<b.size();i++){
			d+=num[b[i]-'a'+1];
		}
		int h=0;
		for(int i=1;i<=n;i++){
			if(c-w[i].sum+w[i].cnt==d){
				h++;
			}
		}
		cout<<h<<"\n";
	} 
	return 0;
} 
