#include<bits/stdc++.h>
using namespace std;
vector<string >p;
string s,s1;
int main(){
	freopen("relace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1;
		if(s1.size()%2==1) s+=s1;
		p.push_back(s);
	}
	for(int i=1;i<=m;i++){
		int mod=50640;
		cout<<p.size()*rand()%mod;
		mod++;
	}
}
/*
The last dance with tree.
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],tr[N];
void update(int ,int );
int query(int );
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
//		update(i,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++){
		int op,x,y,k;
		cin>>op;
		if(op==1){
			cin>>x>>k;
			update(x,k);
//			cin>>x>>y>>k;
//			update(x,k);
//			update(y+1,-k);
		}
		else{
			cin>>x>>y;
			cout<<query(y)-query(x-1)<<"\n";
//			cin>>x;
//			cout<<quert(x);
		}
	}
}
void update(int x,int k){
	while(x<=n){
		tr[x]+=k;
		x+=(x&(-x));
	}
	return;
}
int query(int x){
	int as=0;
	while(x>=1){
		as+=tr[x];
		x-=(x&(-x));
	}
	return as;
}
*/
