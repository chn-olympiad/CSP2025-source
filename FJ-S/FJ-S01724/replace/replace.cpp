#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;
ll n,q,t1,t2,t3,c[N];
short k[5000001][600],h[5000001][600];
string a[N][2],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n>>q;
for(int i=1;i<=n;i++){
cin>>a[i][0]>>a[i][1];
t1=a[i][0].size();
for(int j=0;j<t1;j++){
	if(a[i][0][j]=='b')t2=j;
}	
for(int j=0;j<t1;j++){
	if(a[i][1][j]=='b')t3=j;
}	
c[i]=t3-t2;
if(c[i]>0)k[c[i]][++k[c[i]][0]]=t2;
else h[-c[i]][++h[-c[i]][0]]=t2;
}
while(q--){
	cin>>s1>>s2;
	t1=s1.size();
for(int j=0;j<t1;j++){
	if(s1[j]=='b')t2=j;
}	
for(int j=0;j<t1;j++){
	if(s2[j]=='b')t3=j;
}	
ll ans=0;
if(t3-t2>0){
	for(int i=1;i<=k[t3-t2][0];i++)if(k[t3-t2][i]<=t2)ans++;
	cout<<ans;
}
else {
	for(int i=1;i<=h[t2-t3][0];i++)if(h[t2-t3][i]<=t2)ans++;
	cout<<ans;
}
cout<<endl;
}
	return 0;

}
