#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[3][100005]={0},cnt[3]={0},ch[100005];
int mm(int a,int b,int c){
	if(a>b){
		if(a>c){
			return 0;
		}
		else{
			return 2;
		}
	}
	else{
		if(b>c){
			return 1;
		}
		else{
			return 2;
		}
	}
}
vector<int> v1;
bool cmp1(int o,int p){
	return (a[0][o]+a[1][o]+a[2][o]-2*max(max(a[0][o],a[1][o]),a[2][o])-min(min(a[0][o],a[1][o]),a[2][o]))>(a[0][p]+a[1][p]+a[2][p]-2*max(max(a[0][p],a[1][p]),a[2][p])-min(min(a[0][p],a[1][p]),a[2][p]));
	}
void pa(){
ll ans=0;
	for(int i=0;i<n;i++){
		ans+=a[ch[i]][i];
	}
cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
cnt[0]=cnt[1]=cnt[2]=0;
cin>>n;
v1=vector<int>();
for(int i=0;i<n;i++){
cin>>a[0][i]>>a[1][i]>>a[2][i];
if(a[0][i]>a[1][i]){
	if(a[0][i]>a[2][i]){
		ch[i]=0;
		cnt[0]++;
	}
	else{
		ch[i]=2;
		cnt[2]++;
	}
}
else{
	if(a[1][i]>a[2][i]){
		ch[i]=1;
		cnt[1]++;
	}
	else{
		ch[i]=2;
		cnt[2]++;
	}
}
}
int bz=mm(cnt[0],cnt[1],cnt[2]);
if(cnt[bz]<=n/2){
pa();
continue;
}
for(int i=0;i<n;i++){
	if(ch[i]==bz){
		v1.push_back(i);
		}
	}
sort(v1.begin(),v1.end(),cmp1);
for(int i=0;i<cnt[bz]-n/2;i++){
	ll k=a[0][v1[i]]+a[1][v1[i]]+a[2][v1[i]]-max(max(a[0][v1[i]],a[1][v1[i]]),a[2][v1[i]])-min(min(a[0][v1[i]],a[1][v1[i]]),a[2][v1[i]]);
	if(a[0][v1[i]]==k){
		ch[v1[i]]=0;
		}
	else if(a[1][v1[i]]==k){
		ch[v1[i]]=1;
		}
	else if(a[2][v1[i]]==k){
		ch[v1[i]]=2;
		}
}
pa();
}
return 0;
}