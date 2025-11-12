#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}a[200010];
int n,q;
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int xb=t1.find(a[i].s1);
			//cout<<xb<<endl;
			if(xb==-1) continue;
			string testt=t1;
			for(int f=xb;f<xb+a[i].s1.size();f++){
				testt[f]=a[i].s2[f-xb];
			}
			//cout<<testt;
			if(testt==t2) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
