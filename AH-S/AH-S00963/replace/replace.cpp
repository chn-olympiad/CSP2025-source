#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	int dis;
	int size;
	int jj;
};
node a[2000000];
map<int,int>tong;
    int n,q;
    int flag=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		string c,d;
		cin>>c>>d;
		int m1=0;
		int m2=0;
		for(int j=0;j<c.size();j++){
			if(c[j]=='b')m1=j;
		}
		for(int j=0;j<d.size();j++){
			if(d[j]=='b')m2=j;
			if(d[j]!='a'&&d[j]!='b')flag=1;
		}
		if(flag==1){
			cout<<1;
			return 0;
		}
		a[i].dis=m1-m2;
		//cout<<a[i].dis<<endl;
		a[i].dis+=50000;
		a[i].l=m1;
		a[i].size=c.size();
		a[i].jj=a[i].size-(m1);
		tong[a[i].dis]++;
	}
	long long ans=0;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int m1=0;
		int m2=0;
		ans=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b')m1=i;
		}
		for(int i=0;i<t2.size();i++){
			if(t2[i]=='b')m2=i;
		}
		int c=m1-m2+50000;
		//cout<<c<<endl;
		for(int i=1;i<=n;i++){
			if(a[i].l<=m1&&a[i].dis==c&&m1+a[i].jj<t1.size())ans++;
		}
		//cout<<tong[c]<<endl;
		cout<<ans<<endl;
	}
   return 0;
}
//aab aba
//aaab baaa
// abaaaaaaa 
