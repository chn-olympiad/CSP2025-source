#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,id;
};
int t,n;
bool ctra(node ssc,node ss){
	return ssc.a>ss.a;
}
bool ctrb(node ssc,node ss){
	return ssc.b>ss.b;
}
bool ctrc(node ssc,node ss){
	return ssc.c>ss.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		node s[n+18];
		for(int j=1;j<=n;j++){
			cin>>s[j].a>>s[j].b>>s[j].c;
			s[j].id=j;
		}
		if(n>2){
			int sum=0,sa[100009];
			sort(s+1,s+n+1,ctra);
			for(int i=1;i<=n/2;i++){
				if(s[i].a<s[i].b||s[i].a<s[i].c||sa[s[i].id]==1)continue;
				sum+=s[i].a;
				sa[s[i].id]=1;
			}
			sort(s+1,s+n+1,ctrb);
			for(int i=1;i<=n/2;i++){
				if(s[i].b<s[i].c||sa[s[i].id]==1)continue;
				sum+=s[i].b;
				sa[s[i].id]=1;
			}
			sort(s+1,s+n+1,ctrc);
			for(int i=1;i<=n;i++){
				if(sa[s[i].id]==1)continue;
				sum+=s[i].c;
				sa[s[i].id]=1;
			}
			cout<<sum<<endl;			
		}
		else{
				cout<<max(s[1].a,max(s[1].b,s[1].c))+min(s[1].a,max(s[2].b,s[2].c))<<endl;
				continue;
		}
	}
	return 0;
}
